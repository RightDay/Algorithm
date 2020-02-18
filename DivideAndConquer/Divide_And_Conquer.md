# 분할 정복 (Dvide & Conquer)

## 도입

분할 정복(Dvide & Conquer)은 가장 유명한 알고리즘 디자인 패러다임으로, 각개 격파라는 말로 간단하게 표현이 가능하다. 

분할 정복을 활용한 알고리즘들은 주어진 문제를 **둘 이상의 부분 문제로 나눈 뒤,** 각 문제에 대한 답을 재귀 호출을 이용해 계산하고, 각 부분 문제의 답으로부터 전체 문제의 답을 계산한다. 

*****그림 넣기*

분할 정복은 문제를 한 조각과 나머지로 쪼개는 일반적인 재귀 호출과 달리 **문제를 거의 같은 크기의 부분 문제로 나눈다.** 

#### 분할 정복 알고리즘의 세가지 구성 요소

1. 문제를 더 작은 문제로 분할하는 과정(divide)
2. 각 문제에 대해 구한 답을 원래 문제에 대한 답으로 병합하는 과정(merge)
3. 더이상 답을 분할하지 않고 곧장 풀 수 있는 매우 작은 문제(base case)

#### 예제: 수열의 빠른 합과 행렬의 빠른 제곱

1부터 n까지의 합을 분할정복을 통해 계산하는 $fastSum()$ 함수를 작성해본다.

1부터 n까지의 합을 n개의 조각으로 나눈 뒤, 이들을 반으로 나눠  $\begin{align} \frac n 2 \end{align}$개의 조각들로 만들어준 부분 문제 두 개를 만든다.



$$\begin{alignat}{2}fastSum()&=1+2+\dots+n \\&=(1+2+\dots+\frac n 2) + ((\frac n 2+1)+\dots+n)\end{alignat}$$



첫 번째 부분 문제는 $\begin{align}fastSum(\frac n 2)\end{align}$로 나타낼 수 있지만, 두 번째 부분 문제는 그렇지 않다. 문제를 재귀적으로 풀기 위해서는 각 부분 문제를 '1부터 n까지의 합'으로 표현 할 수 있어야 하는데, 위의 분할에서 두 번째 조각은 'a부터 b까지의 합' 형태를 가지고 있기 때문이다. 따라서 다음과 같이 두 번째 부분 문제를 $fastSum(x)$를 포함하는 형태로 바꿔 써야 한다.

$$\begin{alignat}{2}(\frac n 2 + 1)\dots+n&=(\frac n 2 + 1)+(\frac n 2 + 2)+\dots+(\frac n 2 + \frac n 2) \\ &= \frac n 2 \times \frac n 2 + (1+2+3+\dots+\frac n 2) \\ &= \frac n 2 \times \frac n 2 + fastSum(\frac n 2) \end{alignat}$$

공통된 항$\frac n 2$을 따로 빼내면 $\begin{alignat}{0}fastSum(\frac n 2)\end{alignat}$이 된다. 따라서 다음과 같이 쓸 수 있다.

$$\begin{alignat}{} fastSum(n)=2 \times fastSum(\frac n 2)+ \frac {n^2}2 {}\end{alignat}$$(n이 짝수일 때)



```c++
//필수 조건:n은 자연수
//1+2+\dots+n을 반환한다.
int fastSum(int n)
{
    //기저사례
    if(n == 1) return 1;
    if(n % 2 == 1) return fastSum(n-1) + n;
    return 2 * fastSum(n/2) + (n/2) * (n/2);
}
```



#### 시간 복잡도 분석

$fastSum()$이 종료하는 데 걸리는 시간은 순전히 함수가 호출되는 횟수에 비례하게 된다. 하지만 $fastSum()$은 호출될 때마다 최소한 두 번에 한 번 꼴로 $n$이 절반으로 줄어들기 때문에 일반적인 재귀호출보다 호출 횟수가 적다.

$$ \begin{alignat}{2}fastSum(1011_2)=fastSum(1010_2)+11

fastSum(1010_2)=fastSum(101_2) \times 2 + 25

fastSum(101_2)=fastSum(100_2)+5

fastSum(100_2)=fastSum(10_2)\times 2 + 4

fastSum(10_2)=fastSum(1_2) \times 2 + 1

fastSum(1_2) = 1 $$

















