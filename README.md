# build gdstk for Cpp
gdstk の cpp ビルドが余り見つからなかったので、自分でビルド行うメモ


## 環境構築
### zlibの導入

* vcpkg から zlibのライブラリ導入
    * Debug zlibb.lib
    * Release zlib.lib
* vcpkg 内で以下実行(環境変数設定するまでもないかなって)
```
.\vcpkg\bootstrap-vcpkg.bat

.\vcpkg\vcpkg integrate install  
```
### gdstkのビルド
* visual studio でスタティックライブラリーのプロジェクト作成
* gdstk のソースコード導入

```
git clone git@github.com:heitzmann/gdstk.git  
```
* srcフォルダーの中身をコピーして作成したプロジェクトへ移す
* すべてのファイルをプロジェクトに既存のアイテムとして追加
* Debug Release それぞれ zlibb.lib zlib.lib をプロパティのリンカーへ追加
* zlib のインクルードファイルを追加ディレクトリーへ追加
    * zlib.h
    * zcof.h

あとはビルドした gdstk.lib zlibd.lib zlib.lib とそれぞれの include を外部ライブラリー扱う感じで導入して扱う