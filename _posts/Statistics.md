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

X = 抛N次硬币，硬币正面次数

离散情况下为二项式分布， 连续情况下为正态分布。

$P(X=k) = C_N^kp^k(1-p)^{N-k}$



