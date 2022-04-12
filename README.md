# stm32 library

これは **stm32 library** ソースです。
本ドキュメントはマークダウン書式で記述されています。必要に応じて更新することができます。
- マークダウン書式について
	- https://guides.github.com/features/mastering-markdown/
	- https://qiita.com/tbpgr/items/989c6badefff69377da7

現在プライベート公開です。

## 必要なもの（開発者向け）
- git知識及びクライアント環境
	- まずgit。マスター、ブランチ、Clone、Commit、Push、Pull等
	- PCにgitクライアント環境を用意してください。

## ソース取得方法
- git
	- gitクライアント環境があればCloneで取得できます。アドレスは本サイト `Code -> HTTPS` を参照ください。
- zip
	- 本サイト `Code -> Download ZIP` で取得します。

## ファイル構成

```
ROOT
├ README.md           本ドキュメント
├ LICENCE             本ソースライセンス
│
├ Devices             I2CやSPIを使用したデバイスを集める
│　├ Pressure        圧力センサ
│　├ Temp            温度センサ
│　├  :              
│　├ EEPROM          EEPROMデバイス
│　└                 
├ mbed                mbed to STM32-HAL
├ arduino             arduino to STM32-HAL
├ stm32lib            STM32に依存したライブラリ
│　├ stm32flash      STM32-FLASHを使ったライブラリ
│　├ Stopwatch       計測
│　└                 
├ common              STM32に依存しないライブラリ（他プラットフォームでも利用可能）
│　├ StringBuilder   文字列操作
│　├ json            JSON操作
│　└                 
│
```

## 困った時に
- Pushが出来ません。何が原因でしょうか。
	- https://qiita.com/mokio/items/f6c67c8f9af050383fc0
	- https://docs.github.com/ja/authentication/keeping-your-account-and-data-secure/creating-a-personal-access-token

- ウクライナはどこにあるのでしょうか。志願兵希望です。
	![alt内容](495.jpg)


