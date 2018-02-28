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

#### Sample（样本）和 Population（总体）

样本用于估计总体，总体一般无法统计。

μ = Population Mean = $\frac{1}{N}\sum_{i=1}^nx_i$

$\overline{X}$ = Sample Mean = $\frac{1}{n}\sum_{i=1}^nx_i$

#### 总体方差

Measures of dispersion(离中趋势衡量，其他数字与集中趋势数值的关系情况), 衡量方式：Variance 方差

总体方差 $\sigma^2 = \frac{1}{N}\sum_{i=1}^N(x_i - \mu)^2$

#### Sample Variance(样本方差)

无偏样本方差 $S^2 = \frac{1}{n-1}\sum_{i=1}^n(x - \overline{x})^2$

直观理解样本方差通常会低估总体方差，所以除以 n-1 比 n 更好。[解释](https://www.zhihu.com/question/20099757)

