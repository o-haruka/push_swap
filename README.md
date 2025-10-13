## 実行
```
make
```

## ソート
```
./push_swap 2 1 3 6 5
```

## ソートの成功失敗
```
./push_swap 2 1 3 6 5 | ./checker 2 1 3 6 5 
OK
```

## テスター
```
make tester
```

## メモリリークチェック
```
leaks --atExit -- ./push_swap 3 2 1   
```