## Lection 5: Raft(1)

#### 全局的主题：fault-tolerant services using state machine replication(SRM)

目标： 像非复制服务一样的行为对可见客户端，而且有效的即使一些服务器故障。

策略： 每个复制服务器按相同的顺序执行相同的命令，如果一个故障，其他的继续。

关键的问题： 如何避免 split-brain？：

> 假设客户端可以联系到复制服务 A，无法联系到复制服务 B，客户端可以继续吗，只有Ａ时？
> - 如果 B 已经崩溃，客户端必须继续在没有 B 的情况下，否则这个服务是不可以容错的(tolerate faults)
> - 如果 B 是正常的，只是网络导致无法联系到它，则可能客户端不应该继续，因为他可能是活着，并正常地为其他客户端服务 --- 这就是 split-brain

为什么 split-brain 不被运行的例子:

> fault-tolerant key/value db
> C1: put("k1", "v1")
> C2: put("k2", "v2")
> C1: get("k1") -> ?
> 正确答案应该是 "v2"，因为一个非复制的服务将返回。
> 但是如果两个服务单独服务于 C1 和 C2 由于分隔(partition)，C1 将的得到 "v1"
>

问题: 计算机无法区分 "crashed" 和 "partitioned"

一个状态机的复制规划有:

- 保证有效即使任何一个故障
- 处理分割好分割，没有 split brain 问题
- 如果发生太多故障：等待修复，然后恢复

处理分割的一个见解：多数投票

> 2f + 1 台服务器可以容忍 f 台故障。必须有多数 f + 1 的投票继续运行
> 为什么多数投票可以帮助避免 split brain ?
> ​	至多一个分割区可以有多数的服务器，多数是指所有的 2f + 1 的服务器，而不仅仅是只有活着的。
>  the really useful thing about majorities is that any two must intersect
>  	servers in the intersection will only vote one way or the other
>  	and the intersection can convey information about previous decisions

#### Raft

如果旧的领导者没有发现新的领导者被选出会如何？
> 可能旧的领导者没有看见选举消息
> 可能旧的领导者在一个小的网络分区内
> 新的领导者意味多数已经增加任期号的服务器，
> 　因此旧的领导者不可能的多数服务器的 AppendEntries 回应
> 　因此旧的领导者无法提交或执行任何新的提交日志
> 　所有不会有 split brain
> 　但是少数的服务器可能接受旧的领导者的 AppendEntries
> 　  因此有分叉在旧任期结束时(这些后续都会被覆盖)