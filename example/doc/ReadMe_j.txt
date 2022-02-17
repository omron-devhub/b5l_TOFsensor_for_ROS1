------------------------------------------------
 B5L ROS Publisher サンプルコード （C++版）
------------------------------------------------

（1）サンプルコード内容
  本サンプルは、B5L(3D TOFセンサモジュール)からの計測情報をROS上のTopicとして
  発行するコード例です。
  ToF_Sample.prmファイルに記載されたパラメータに従ってB5Lを初期化し、取得した
  データをsensor_msgs/PointCloud2形式のTopicから取得できます。

（2）ファイル説明
  TOFSensorSampleROS1CPP/フォルダーには、次のファイルが存在します。

    omron_b5l_a/include/omron_b5l_a/*              ヘッダファイル
    omron_b5l_a/src/config/ToF_Sample.prm          パラメータ設定ファイル
    omron_b5l_a/src/publisher_member_function.cpp  サンプルコード本体
    omron_b5l_a/src/ToF_Sample.cpp                 ToF通信処理
    omron_b5l_a/src/TOFApiZ.cpp                    ToFコマンドクラス
    omron_b5l_a/src/uart_linux.c                   UART通信処理
    omron_b5l_a/CMakeLists.txt                     CMake設定ファイル
    omron_b5l_a/connect_tof.sh                     B5L接続用シェルスクリプト
    omron_b5l_a/package.xml                        Package定義ファイル
    Quick Setup Guide_ROS.pdf                      セットアップガイド(英語)
    Quick Setup Guide_ROS_JP.pdf                   セットアップガイド

（3）サンプルコードのビルド方法
  1. 本サンプルコードは、Ubuntu18.04 / ROS Melodic Morenia上で動作確認されて
     います。
  2. 具体的なセットアップ手順については、Quick Setup Guide_ROS_JP.pdfを
     参照してください。

【使用上の注意】
* 本サンプルコードおよびドキュメントの著作権はオムロンに帰属します。
* 本サンプルコードは動作を保証するものではありません。
* 本サンプルコードは、Apache License 2.0にて提供しています。

----
オムロン株式会社
Copyright 2020-2022 OMRON Corporation、All Rights Reserved.
