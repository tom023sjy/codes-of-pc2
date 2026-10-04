#### 问题陈述

给你一个长度为 $N$ 的整数序列 $A=(A _ 1,A _ 2,\ldots,A _ N)$ 。

您要对 $A$ 执行以下操作**只进行一次**。

- 在 $1$ 和 $N-K+1$ （含）之间选择一个整数 $i$ 。将 $A _ i,A _ {i+1},\ldots,A _ {i+K-1}$ 按升序排序。更具体地说，让 $B _ 1,B _ 2,\ldots,B _ K$ 成为按升序排列的 $A _ i,A _ {i+1},\ldots,A _ {i+K-1}$ ，同时用 $B _ j$ 替换 $A _ {i+j-1}$ 为 $1\le j\le K$ 。

判断经过这样的操作后， $A$ 是否有可能是升序排列，即 $A _ i\le A _ {i+1}$ 对所有的 $1\le i\lt N$ 都成立。

### Input

The input is given from Standard Input in the following format:

```
$N$ $K$
$A _ 1$ $A _ 2$ $\ldots$ $A _ N$
```