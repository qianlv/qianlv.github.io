## 统计学(Statistics)

介绍：

1. 描述统计学
2. 推论统计学

### 描述统计学

#### Central tendency(集中趋势)

“Averrage(平均值)”，描述集中趋势的某特定数值。

衡量集中趋势方式：

1. Mean(算术平均值)
2. Median(中位数)
3. mode(众数)

Mean 容易受到outlier（离群值, 明显不同的值，源于测量错误或其他原因)的影响，而偏离, 例如 3, 3, 3, 3, 100 中的 100 这个离群值。

#### Sample (样本) 和 Population (总体)

样本用于估计总体，总体一般无法统计。

μ = Population Mean = $\frac{1}{N}\sum_{i=1}^nx_i$

$\overline{X}$ = Sample Mean = $\frac{1}{n}\sum_{i=1}^nx_i$

#### Population (总体方差)

Measures of dispersion(离中趋势衡量，其他数字与集中趋势数值的关系情况), 衡量方式：Variance 方差

总体方差 $\sigma^2 = \frac{1}{N}\sum_{i=1}^N(x_i - \mu)^2​$

#### Sample Variance(样本方差)

无偏样本方差 $S^2 = \frac{1}{n-1}\sum_{i=1}^n(x - \overline{x})^2$

直观理解样本方差通常会低估总体方差，所以除以 n-1 比 n 更好。[解释](https://www.zhihu.com/question/20099757)

#### Standard Variance(标准差)

$\sigma = \sqrt{\sigma^2}$

$S  = \sqrt{S^2}$

#### 方差公式转换

$ \sigma^2 = \frac{1}{N}\sum_{i=1}^N(x_i - \mu)^2 = \frac{1}{N}\sum_{i=1}^N{x_i}^2 - \mu^2$

#### 随机变量

大写字母表示，用于区分传统的变量。

从随机过程映射道数值的函数, 如 
$$
X = \begin{cases}
1, if \ rainning\ tomorrow \\
0, don't\ rain
\end{cases}
$$
或 X = 骰子抛出的数值

分为：

1. 离散(Discrete)随机变量: 变量个数有限。
2. 连续(Continue)随机变量: 变量范围可能有限，但个数无限。

#### 概率密度函数(Probability density function)

对于连续随机变量，某个具体值的概率值为0，一定范围内的变量才有概率值且有意义。

概率密度函数，用于计算连续变量某个范围空间内的概率。
$$
f(x) > 0 \\
\int_{-\infty}^{+\infty}f(x)dx = 1 \\
P(a < x <= b) = \int_a^bf(x)dx
$$

#### 二项式分布

X = 抛n次硬币，硬币正面次数

离散情况下为二项式分布， 连续情况下为正态分布。

$P(X=k) = C_n^kp^k(1-p)^{n-k}$

#### 期望值 E(X)

期望值的计算等同于总体均值计算，由于总体为无穷个数，所以用频率作为权重，计算加权平均数。

#### 二项式分布的期望值

X = n次实验成功的次数，其中每次成功的概率为p，$E(X) = np$

#### 泊松分布

X = 一小时内通过的车辆数，假设任意时刻，车流量都没有差异。

假设 $E(X) = \lambda$, 假设满足二项式分布，$\lambda = np => p = \frac{\lambda}{n}$

这里 $\lambda$ 表示每小时通过的车辆数, n 表示实验次数(每分钟出现的车辆数， 或更小的每秒，等等)，p 表示每次实验出现车辆的概率。

一小时内出现k辆车的概率 $P(X=k) = \lim_{n\rightarrow+\infty}{C_n^k\frac{\lambda}{n}^k(1-\frac{\lambda}{n})^{n-k}}  = \frac{\lambda}{n!}e^{-\lambda}$

假设 n = 60，那么每次实验就表示每分钟通过1辆车的概率为 p， 60次实验的二项式分布。

当n趋于无穷大时，则是泊松分布。

#### 大数定律

样本足够大，那么样本均值趋近于期望值。

赌徒谬误（gambler‘s fallacy）是生活中常见的一种不合逻辑的推理方式，认为一系列事件的结果都在某种程度上隐含了自相关的关系，即如果事件A的结果影响到事件B，那么就说B是“依赖”于A的。例如，一晚上手气不好的赌徒总认为再过几把之后就会风水轮流转，幸运降临。相反的例子，连续的好天气让人担心周末会下起大雨。

大数定律根本不关心那些有限次实验，后面还有无限次实验使收敛于期望值。

### 推论统计学

#### 正态分布

正态分布概率密度函数 $p(x) = \frac{1}{\sigma\sqrt{2\pi}}exp(-\frac{(x-\mu)^2}{2\sigma^2}) = \frac{1}{\sqrt{2\pi\sigma^2}}e^{-\frac{1}{2}(\frac{x-\mu}{\sigma})^2}$



