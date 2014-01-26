這題如果 tick by day 肯定會 TLE，所以我構想了兩個加速的方法：(1)tick by month、(2)tick by year。
tick by month 還比較單純，tick by year貌似太麻煩容易寫爛。

最後發現這題 tick by month 就剛好 AC 了。

注意閏年判斷的順序是除 400、除 100、除 4。
