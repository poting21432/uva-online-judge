這題是經典的 O(n lg n) 時間求 2D closest pair of points.

只要用典型的 Divide and conquer 演算法就可以解決。

關於過程中的點排序，需注意以下幾點：

1. 在演算法開始之前，需將所有點按照 x 座標排序 (以分為左右兩半)。

2. 在 combine 階段，需仿照 mergeSort() 的 merge 將左右兩半「根據 y 座標」合併。這樣做的目的是為了在每個子區間 [L,R] 可以用 O(n) 時間得到「按照 y 座標排序」的 strip。要是不這樣做的話，整體算法就不會是 O(n lg n)。

以下是作 closest pair of points 常見的盲點：

1. 區間只剩 1、2、3 個點時，都可以單獨處理，到 4 個點以上再 divide。

2. 切記要先檢查是否有「重複的點」，如果有的話答案就是 0。

至於整體時間複雜度，因為每次花 O(n) 時間 merge：

> T(n) = 2T(n/2) + O(n)

根據 Master Theorem Case (2)，a=2, b=2，所以

> T(n) = O(n lg n)
