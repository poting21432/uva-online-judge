沒講 n 多大。但 O(n^2) 會 TLE、O(n lg n) 才可 AC。

O(n lg n) LIS 的想法是動態維護一個「偽 LIS」，每此看一個元素 x：

(1) 要麼 x 可接在 偽 LIS 後面 => 接在 LIS 後面
(2) 要麼 x 不可接在後面 => 插入 LIS 中適當的位置 (binary search)

但是 (2) 會破壞 LIS 的順序，所以我說它是「偽 LIS」。

這題要印出 LIS 的內容，這邊我想了很久，現在的方法是這樣：
1. 將每項和它的 index 包成 struct
2. 和 O(n^2) 一樣維護 pre[] 和 end (end是最長LIS的尾巴)
3. 上述(1)把A[i]接在LIS後面時，順便把 pre[i] 設為 LIS 尾巴的 index。
4. 上述(2)把A[i]插入LIS適當位置時，把 pre[i] 設為「此位置前一項的 index」。
5. 上述(2)有的時候會剛好插在LIS的尾巴，這時候也要更新 end。