這題我 O(n^2) LIS 會 TLE，換成 O(nlgn) LIS 就 AC 了。

O(nlgn) LIS 要再自己維護原本類似 O(n^2) LIS 的表格 f[i] 紀錄「以 i 結尾的最長LIS長度」。
