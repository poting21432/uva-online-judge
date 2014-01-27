這題沒有講 n 多大，不過 O(n^2) 可 AC。

這題是 LIS 變形、要最大化的不是 LIS 的項數、而是另外定義的「width」。

所以我們可以把 O(n^2) LIS 邊界條件設為 f(i)=width(i)、狀態轉移設為 f(i)=max{f(j)+width[i]}。

尚未想通這種變形的 LIS 可否用 O(n lg n) 解。
