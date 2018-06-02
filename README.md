Sample Code for Drones
---

### Files
- README.md  
it's me.
- Makefile  
- main.c
- drone.h
- ardrone2.c

### How to run
1. AR.Drone2のAP(wifi)につなぐ

1. プログラムを実行する
```
$ make run
```

### Docs
ARDrone Developper's Guide in [SDK2](http://developer.parrot.com/products.html) by Parrot.

### Note
- スムーズに動かすには, 30ms毎にAR-commandsを送ると良い
- Wifiの接続が切れないようにするためにはおそくと, も2秒毎にAT-commandsを送らなければならない
