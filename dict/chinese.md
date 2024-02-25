# 長頸鹿大冒險

## 敘述內容

這是一個基於 [PTSD] 框架所打造的一個小小練習課程，主要目的為提供 OOPL2024F(物件導向實習) 的學生練習。

## 如何安裝

1. 下載此專案

```bash
git clone https://github.com/ntut-open-source-club/PTSD-Practice-Giraffe-Adventure --recursive
```

## 配置設定 (可選)

以下的 [config.hpp](PTSD/include/config.hpp) 都在此路徑上：`PTSD/include/config.hpp`

- 調整 `config.hpp` 當中的 `寬` 與 `高`，並設定為數值 `601`。

- 調整 `config.hpp` 當中的幀率 (一秒內螢幕更新的次數) ，預設為 60 fps。

- 調整 `config.hpp` 你想要的遊戲名稱。

## 任務

- [ ] 把在這個練習檔案裡面 (你必須自行尋找)，會出現一個物件名稱 `m_giraffe`，並且將該物件名稱的路徑變更為 Rescoures 資料夾底下的 `giraffe.png`。

- [ ] 想一想，如何使用鍵盤控制一隻該死的長頸鹿到紅色框框內。PS: 可以透過提供的 `API` 來查詢觸發鍵盤的條件。

- [ ] 今天，長頸鹿肚子餓了，而眾所周知長頸鹿最愛吃寶箱了。所以你必須讓長頸鹿碰觸到寶箱時，寶箱就會被消失

- [ ] 蜜蜂是我們的好朋友，而你 我的朋友 寫一個程式讓蜜蜂動起來吧! 觀察一下各個文件的呼叫，試試看新增或者修改哪些 method 能讓蜜蜂動起來~

- [ ] 那該死的長頸鹿又餓了，因此他必須從每一扇門後面看看可憐的寶箱有沒有在裡面。你的任務是，當長頸鹿走過每一扇門後... 那扇門就要開啟。至此才算完成這一關卡。

- [ ] Design a program to countdown, stop animation after OK display.

###### Hint: 當你在上述某一項任務卡住的時候，多多看看每一份程式檔案。裡面會有一些長頸鹿拉下來的一坨提示 `TODO: ......`，去發現它吧! ~~帶領著長頸鹿成為海賊王~~
