# Red-black-tree-C

C语言实现的红黑树

### 完整输出

- 1 代表 黑色，0 代表 红色
- rbtest 主要验证：从任一节点到其每个叶子的所有简单路径都包含相同数目的黑色节点
- rbtest 输出不存在 0 证明是符合要求的红黑树
```cpp
This is red black tree.
1 is black, 0 is red.
If the rbtest output is all 1, five characteristics are met.

r b tree init : 1, 2, 3, 4, 5, 6, 7, 8, 9
4(1)
|----- 2(0)
|   |----- 1(1)
|   ------ 3(1)
------ 6(0)
    |----- 5(1)
    ------ 8(1)
        |----- 7(0)
        ------ 9(0)

rbtest : 1 1 1 1

r b tree del : 6
4(1)
|----- 2(0)
|   |----- 1(1)
|   ------ 3(1)
------ 7(0)
    |----- 5(1)
    ------ 8(1)
        |----- 
        ------ 9(0)

rbtest : 1 1 1 1
```
