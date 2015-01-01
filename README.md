Suggest-DP-Matching-Word
========================

##概要

###予測変換ソフト
本ソフトウェアは，[AD]のレポートを書くことに対する負担の軽減のため，あらかじめ[AD]のレポートによく用いるであろう単語や文節をファイルに登録しておき，ユーザの入力からユーザが
入力したいであろう語句を推測し変換するソフト．


##使用方法
`newsdp4.exe` を実行すると，「./newsdp4/worddata.csv」 を読み込んでコマンドプロンプトに表示される．

予測変換の候補を表示するには，`ひらがな`で入力し，ある程度の変換したい文字(2~3文字)入力し，`Enterキー`を押すことでDPマッチングによる変換候補が表示される．`矢印キー`で変換したい文字を選択し，再び`Enterキー`で確定することで文字を打つことができる.  

`:(セミコロン)`*(vim風?)* の一語 を入力すると 「レポート編集モード」 となり，保存等の処理が行える．
具体的には以下のメニューが表示される．

    レポートファイル編集メニュー
    
    [ESC]:ファイルを保存して終了
    [BackSpace]:単語削除
    [T]:ツイート用HTMLファイル作成
    [:(コロン)]:コロン(:)を入力
    [その他のキー]:キャンセル
    ----------コマンドを入力してください---------------
    
    Command:

この時，`Command:`に`T`を入力して`Enterキー`を押すことでTwitterに投稿できるHTMLファイルが生成され，簡単にツイートできるようになる．


##動作環境
動作確認済みOS: Windows 8.1(64bit)

Eclipse CDTを用いてC言語で作成したため，32bit版Windowsで実行したい場合には，プロジェクトをインポートして再びコンパイルする必要がある．

##本ソフトウェアの開発の条件
条件を満たして開発を行う

1. アイデアだけでなく，具体的なソフトウェアとしてそのアイデアを実現すること
(例えば，実行したときの動作イメージなど)
 実行画面に言葉を入力して，その後に*特定のコマンド* または *キー操作* をすることによって，イメージとしては携帯電話でよくあるような，
`「単語の一部を入力すると打ちたい単語の候補が表示される」`
ソフトウェアを作成する．  
具体的な要求は以下の通り
   * 変換候補の一覧を表示させ，ユーザが決定する．
   * 変換結果はファイルなどで出力する．  

1. 具体的に「誰かの役に立つもの」であること（具体的には，その人から`500円`くらいならもらっても大丈夫なくらいのものであること．もちろん，役に立つ「誰か」の人数は多いほうがよい）．

1. 今回は，予測変換できる単語の候補を[AD]など，情報学でよく使う単語に限定する．主な対象は`情報学を専攻する大学生`と`その教員`で，入力作業（レポートの作成など）の効率化にわずかながらかもしれないが貢献することができる．

1. この授業・演習で学んだアルゴリズムやデータ構造やプログラミングの知識などを活かしたものであること．`動的計画法を応用したDPマッチング`をもとに，予測変換のアルゴリズムを作り出す．

1. 開発メンバーが楽しい人たちばかりなので，開発メンバーが楽しんで取り組めるような内容であり，楽しく取り組める．

##具体的な開発期間
具体的にどのような手順でソフトウェアとして完成させるのか以下の物を作成した．  

概ね以下のような計画でいた．

* 辞書ファイルの読み込み：1時間程度
* ユーザ入力：2時間程度
* 文字列マッチング：3時間程度
* ユーザが選択する機能：1時間程度
* 表示とファイル出力:2時間程度

計9時間程度となっている．  
ただし，実装の時間の4倍くらい計画を立てるのに時間を必要とする．

実際に行った結果は以下のとおりである．
それぞれ全部別人となるように，グループメンバーでうまく分担した．

* 辞書ファイルの読み込み：2時間程度
* ユーザ入力：1時間程度
* 文字列マッチング：2時間程度
* ユーザが選択する機能：1時間程度
* 表示とファイル出力：2時間程度

また，これに加えて，次の機能を追加実装した．

* 入力した文章に対する単語ごとの削除機能：3時間程度
* 文章のTwitter投稿機能：4時間程度
