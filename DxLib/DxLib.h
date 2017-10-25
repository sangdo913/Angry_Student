// -------------------------------------------------------------------------------
// 
// 		ＤＸライブラリ		ヘッ?フ?イル
// 
// 				Ver 3.05
// 
// -------------------------------------------------------------------------------

#ifndef __DXLIB
#define __DXLIB

#include <tchar.h>

// ＤＸライブラリのバ?ジョン
#define DXLIB_VERSION 0x3050
#define DXLIB_VERSION_STR _T( "3.05" )

// 設定 -----------------------------------------------------------------------

// ＤＸライブラリに必要な lib フ?イルを、プロジェクトのカレントフォル?や
// コンパイラのデフォルト LIB パスに設定せずに使用される場合は以下の
// コメントを外してください
//#define DX_LIB_NOT_DEFAULTPATH

#ifndef __DX_MAKE

// ?画関連の関数を一切使用されない場合は以下のコメントを外して下さい
//#define DX_NOTUSE_DRAWFUNCTION

#endif

// ?定? ---------------------------------------------------------------------

// ＤｉｒｅｃｔＩｎｐｕｔのバ?ジョン設定
#define DIRECTINPUT_VERSION 0x700

#include <windows.h>
#include <stdio.h>

#ifndef DWORD_PTR
#define DWORD_PTR	DWORD
#endif

#ifndef LONG_PTR
#define LONG_PTR	DWORD
#endif

// ＤｉｒｅｃｔＸ関連定?部 ---------------------------------------------------

#include "DxDirectX.h"
/*
#ifdef DX_USE_DIRECTX_SDK_FILE
	#include <dinput.h>
	#include <ddraw.h>
	#include <d3d.h>
	#ifndef DX_NON_MOVIE
		#include <dshow.h>
	#endif
	#include <qedit.h>
	#include <stdio.h>
	#include <dsound.h>
	#include <dmusici.h>
#else
	#include "DxDirectX.h"
#endif
*/

// ライブラリリンク定?--------------------------------------------------------

#ifndef __DX_MAKE
	#ifndef DX_LIB_NOT_DEFAULTPATH
		#ifndef DX_SRC_COMPILE
			#ifdef _DEBUG
				#ifdef UNICODE
					#pragma comment( lib, "DxLibW_d.lib"		)		//  ＤＸライブラリ使用指定
					#pragma comment( lib, "DxUseCLibW_d.lib"		)	//  標?Ｃライブラリを使用する部分の lib フ?イルの使用指定
				#else
					#pragma comment( lib, "DxLib_d.lib"		)			//  ＤＸライブラリ使用指定
					#pragma comment( lib, "DxUseCLib_d.lib"		)		//  標?Ｃライブラリを使用する部分の lib フ?イルの使用指定
				#endif
				#pragma comment( linker, "/NODEFAULTLIB:libcmt.lib" )
				#pragma comment( linker, "/NODEFAULTLIB:libc.lib" )
				#pragma comment( linker, "/NODEFAULTLIB:libcd.lib" )
	//			#pragma comment( linker, "/NODEFAULTLIB:msvcrt.lib" )
	//			#pragma comment( linker, "/NODEFAULTLIB:msvcrtd.lib" )
			#else
				#ifdef UNICODE
					#pragma comment( lib, "DxLibW.lib"		)			//  ＤＸライブラリ使用指定
					#pragma comment( lib, "DxUseCLibW.lib"		)		//  標?Ｃライブラリを使用する部分の lib フ?イルの使用指定
				#else
					#pragma comment( lib, "DxLib.lib"		)			//  ＤＸライブラリ使用指定
					#pragma comment( lib, "DxUseCLib.lib"		)		//  標?Ｃライブラリを使用する部分の lib フ?イルの使用指定
				#endif
				#pragma comment( linker, "/NODEFAULTLIB:libcmtd.lib" )
				#pragma comment( linker, "/NODEFAULTLIB:libc.lib" )
				#pragma comment( linker, "/NODEFAULTLIB:libcd.lib" )
	//			#pragma comment( linker, "/NODEFAULTLIB:msvcrt.lib" )
	//			#pragma comment( linker, "/NODEFAULTLIB:msvcrtd.lib" )
			#endif
			#pragma comment( lib, "DxDrawFunc.lib"		)			//  ?画部分の抜き出し
		#endif
		//#pragma comment( lib, "libcmt.lib"		)				//  C標??ル?スレッド対応ライブラリ
		#pragma comment( lib, "kernel32.lib"		)			//  Win32カ?ネルライブラリ
		//#pragma comment( lib, "comctl32.lib"		)			//?Win32API用ライブラリ
		#pragma comment( lib, "user32.lib"		)				//  Win32API用ライブラリ
		#pragma comment( lib, "gdi32.lib"		)				//  Win32API用ライブラリ
		#pragma comment( lib, "advapi32.lib"		)			//  Win32API用ライブラリ
		//#pragma comment( lib, "ole32.lib"		)				//  Win32API用ライブラリ
		#pragma comment( lib, "shell32.lib"		)				//  ?ル?メディアライブラリ
		//#pragma comment( lib, "winmm.lib"		)				//  ?ル?メディアライブラリ
		#ifndef DX_NON_MOVIE
			//#pragma comment( lib, "Strmiids.lib" )			//?DirectShow用ライブラリ
		#endif
		#ifndef DX_NON_NETWORK
			//#pragma comment( lib, "wsock32.lib" )				//  WinSockets用ライブラリ
		#endif
		#ifndef DX_NON_KEYEX
			//#pragma comment( lib, "imm32.lib" )					// ＩＭＥ?作用ライブラリ
		#endif
		#ifndef DX_NON_ACM
			//#pragma comment( lib, "msacm32.lib" )				// ?ＣＭ?作用ライブラリ 
		#endif
		#ifndef DX_NON_PNGREAD
			#ifdef _DEBUG
				#pragma comment( lib, "libpng_d.lib" )			// ＰＮＧ用ライブラリ
				#pragma comment( lib, "zlib_d.lib" )
			#else
				#pragma comment( lib, "libpng.lib" )			// ＰＮＧ用ライブラリ
				#pragma comment( lib, "zlib.lib" )
			#endif
		#endif
		#ifndef DX_NON_JPEGREAD
			#ifdef _DEBUG
				#pragma comment( lib, "libjpeg_d.lib" )			// ＪＰＥＧ用ライブラリ
			#else
				#pragma comment( lib, "libjpeg.lib" )			// ＪＰＥＧ用ライブラリ
			#endif
		#endif
		#ifndef DX_NON_OGGVORBIS								// ＯｇｇＶｏｒｂｉｓ用ライブラリ
			#ifdef _DEBUG
				#pragma comment( lib, "ogg_static_d.lib" )
				#pragma comment( lib, "vorbis_static_d.lib" )
				#pragma comment( lib, "vorbisfile_static_d.lib" )
			#else
				#pragma comment( lib, "ogg_static.lib" )
				#pragma comment( lib, "vorbis_static.lib" )
				#pragma comment( lib, "vorbisfile_static.lib" )
			#endif
		#endif
		#ifndef DX_NON_OGGTHEORA								// ＯｇｇＴｈｅｏｒａ用ライブラリ
			#ifdef _DEBUG
				#pragma comment( lib, "ogg_static_d.lib" )
				#pragma comment( lib, "vorbis_static_d.lib" )
				#pragma comment( lib, "vorbisfile_static_d.lib" )

				#pragma comment( lib, "libtheora_static_d.lib"		)		//  ＤＸライブラリ使用指定
			#else
				#pragma comment( lib, "ogg_static.lib" )
				#pragma comment( lib, "vorbis_static.lib" )
				#pragma comment( lib, "vorbisfile_static.lib" )

				#pragma comment( lib, "libtheora_static.lib"		)		//  ＤＸライブラリ使用指定
			#endif
		#endif
	#endif
#endif

/*
#ifndef __DX_MAKE
	#pragma comment( linker, "/NODEFAULTLIB:libc.lib" )
	#pragma comment( linker, "/NODEFAULTLIB:libcd.lib" )
	#pragma comment( linker, "/NODEFAULTLIB:libcmtd.lib" )
	#pragma comment( linker, "/NODEFAULTLIB:msvcrt.lib" )
	#pragma comment( linker, "/NODEFAULTLIB:msvcrtd.lib" )
#endif
*/

/*
#ifndef __DX_MAKE
	#ifdef _DEBUG
		#ifndef DX_USE_VISUALC_MEM_DEBUG
			#pragma comment( linker, "/NODEFAULTLIB:libc.lib" )
			#pragma comment( linker, "/NODEFAULTLIB:libcd.lib" )
//			#pragma comment( linker, "/NODEFAULTLIB:libcmt.lib" )
			#pragma comment( linker, "/NODEFAULTLIB:libcmtd.lib" )
			#pragma comment( linker, "/NODEFAULTLIB:msvcrt.lib" )
			#pragma comment( linker, "/NODEFAULTLIB:msvcrtd.lib" )
		#else
			#pragma comment( linker, "/NODEFAULTLIB:libc.lib" )
			#pragma comment( linker, "/NODEFAULTLIB:libcd.lib" )
			#pragma comment( linker, "/NODEFAULTLIB:libcmt.lib" )
		#endif
	#else
		#pragma comment( linker, "/NODEFAULTLIB:libc.lib" )
		#pragma comment( linker, "/NODEFAULTLIB:libcd.lib" )
//		#pragma comment( linker, "/NODEFAULTLIB:libcmt.lib" )
		#pragma comment( linker, "/NODEFAULTLIB:libcmtd.lib" )
		#pragma comment( linker, "/NODEFAULTLIB:msvcrt.lib" )
		#pragma comment( linker, "/NODEFAULTLIB:msvcrtd.lib" )
	#endif
#endif
*/

/*
#ifndef __DX_MAKE
	#ifdef _DEBUG
		#pragma comment( linker, "/NODEFAULTLIB:libc.lib" )
//		#pragma comment( linker, "/NODEFAULTLIB:libcmt.lib" )
		#pragma comment( linker, "/NODEFAULTLIB:msvcrt.lib" )
		#ifdef DX_USE_MULTITASK_LIB
			#pragma comment( linker, "/NODEFAULTLIB:libcd.lib" )
		#else
			#pragma comment( linker, "/NODEFAULTLIB:libcmtd.lib" )
			#pragma comment( linker, "/NODEFAULTLIB:msvcrtd.lib" )
		#endif
	#else
		#pragma comment( linker, "/NODEFAULTLIB:libc.lib" )
		#pragma comment( linker, "/NODEFAULTLIB:libcd.lib" )
		#pragma comment( linker, "/NODEFAULTLIB:libcmtd.lib" )
		#pragma comment( linker, "/NODEFAULTLIB:msvcrtd.lib" )
		#ifdef DX_USE_MULTITASK_LIB
			#pragma comment( linker, "/NODEFAULTLIB:libc.lib" )
		#else
//			#pragma comment( linker, "/NODEFAULTLIB:libcmt.lib" )
			#pragma comment( linker, "/NODEFAULTLIB:msvcrt.lib" )
		#endif
	#endif
#endif
*/


#ifdef DX_USE_DIRECTX_SDK_FILE
	#ifndef __DX_MAKE
		#ifdef __BCC
			#ifdef strcpy
			#undef strcpy
			#endif
			
			#ifdef strcat
			#undef strcat
			#endif
			
			#ifdef sprintf
			#undef sprintf
			#endif
			
			#ifdef vsprintf
			#undef vsprintf
			#endif
		#endif
	#endif

	// strsafe.h への対抗策
	#undef lstrcpy
	#undef lstrcat
	#undef wsprintf
	#undef wvsprintf
	#undef StrCpy
	#undef StrCat
	#undef StrNCat
	#undef StrCatN

	#undef lstrcpyA
	#undef lstrcpyW
	#undef lstrcatA
	#undef lstrcatW
	#undef wsprintfA
	#undef wsprintfW

	#undef StrCpyW
	#undef StrCatW
	#undef StrNCatA
	#undef StrNCatW
	#undef StrCatNA
	#undef StrCatNW
	#undef wvsprintfA
	#undef wvsprintfW

	#undef _tcscpy
	#undef _ftcscpy
	#undef _tcscat
	#undef _ftcscat
	#undef _stprintf
	#undef _sntprintf
	#undef _vstprintf
	#undef _vsntprintf
	#undef _getts

	#undef strcpy
	#undef wcscpy
	#undef strcat
	#undef wcscat
	#undef sprintf
	#undef swprintf
	#undef vsprintf
	#undef vswprintf
	#undef _snprintf
	#undef _snwprintf
	#undef _vsnprintf
	#undef _vsnwprintf
	#undef gets
	#undef _getws

	#ifdef UNICODE
	#define lstrcpy    lstrcpyW
	#define lstrcat    lstrcatW
	#define wsprintf   wsprintfW
	#define wvsprintf  wvsprintfW
	#else
	#define lstrcpy    lstrcpyA
	#define lstrcat    lstrcatA
	#define wsprintf   wsprintfA
	#define wvsprintf  wvsprintfA
	#endif

	#ifdef UNICODE
	#define StrCpy  StrCpyW
	#define StrCat  StrCatW
	#define StrNCat StrNCatW
	#else
	#define StrCpy  lstrcpyA
	#define StrCat  lstrcatA
	#define StrNCat StrNCatA
	#endif

	#ifdef _UNICODE
	#define _tcscpy     wcscpy
	#define _ftcscpy    wcscpy
	#define _tcscat     wcscat
	#define _ftcscat    wcscat
	#define _stprintf   swprintf
	#define _sntprintf  _snwprintf
	#define _vstprintf  vswprintf
	#define _vsntprintf _vsnwprintf
	#define _getts      _getws
	#else
	#define _tcscpy     strcpy
	#define _ftcscpy    strcpy
	#define _tcscat     strcat
	#define _ftcscat    strcat
	#define _stprintf   sprintf
	#define _sntprintf  _snprintf
	#define _vstprintf  vsprintf
	#define _vsntprintf _vsnprintf
	#define _getts      gets
	#endif

	#define strcpy	_STRCPY
	#define strcat	_STRCAT
#endif

// 定?---------------------------------------------------------------------------

// π
#define PHI							(3.1415926535897932384626433832795 )
#define PHI_F						(3.1415926535897932384626433832795f)
#define TWO_PHI						(3.1415926535897932384626433832795  * 2.0 )
#define TWO_PHI_F					(3.1415926535897932384626433832795f * 2.0f)

#define DX_CHAR										char

#define DX_DEFINE_START

#define MAX_IMAGE_NUM								(32768)				// 同時に持てるグラフィックハンドルの最大数( ハンドルエラ??ェックの?スクに使用しているので 65536 以下の 2 のべき乗にして下さい )
#define MAX_2DSURFACE_NUM							(32768)				// ２Ｄサ?フェスデ??の最大数( ハンドルエラ??ェックの?スクに使用しているので 65536 以下の 2 のべき乗にして下さい )
#define MAX_3DSURFACE_NUM							(65536)				// ３Ｄサ?フェスデ??の最大数( ハンドルエラ??ェックの?スクに使用しているので 65536 以下の 2 のべき乗にして下さい )
#define MAX_IMAGE_DIVNUM							(64)				// 画像分割の最大数
#define MAX_SURFACE_NUM								(65536)				// サ?フェスデ??の最大数
#define MAX_SOFTIMAGE_NUM							(8192)				// 同時に持てる祖父とイメ?ジハンドルの最大数( ハンドルエラ??ェックの?スクに使用しているので 65536 以下の 2 のべき乗にして下さい )

#define MAX_SOUND_NUM								(32768)				// 同時に持てるサウンドハンドルの最大数
#define MAX_SOFTSOUND_NUM							(8192)				// 同時に持てる?フトウエアサウンドハンドルの最大数
#define MAX_MUSIC_NUM								(256)				// 同時に持てる?ュ?ジックハンドルの最大数
#define MAX_MOVIE_NUM								(100)				// 同時に持てる??ビ?ハンドルの最大数
#define MAX_MASK_NUM								(512)				// 同時に持てる?スクハンドルの最大数
#define MAX_FONT_NUM								(40)				// 同時に持てるフォントハンドルの最大数
#define MAX_INPUT_NUM								(256)				// 同時に持てる文字列入力ハンドルの最大数
#define MAX_SOCKET_NUM								(8192)				// 同時に持てる通信ハンドルの最大数
#define MAX_LIGHT_NUM								(4096)				// 同時に持てるライトハンドルの最大数
#define MAX_SHADER_NUM								(4096)				// 同時に持てるシェ???ハンドルの最大数
#define MAX_VERTEX_BUFFER_NUM						(16384)				// 同時に持てる頂?バッフ?ハンドルの最大数
#define MAX_INDEX_BUFFER_NUM						(16384)				// 同時に持てるインデックスバッフ?の最大数

#define MAX_JOYPAD_NUM								(16)				// ジョイパッドの最大数
#define MAX_EVENTPROCESS_NUM						(5)					// 一度に処理するイベントの最大数

#define DEFAULT_SCREEN_SIZE_X						(640)				// デフォルトの画面の幅
#define DEFAULT_SCREEN_SIZE_Y						(480)				// デフォルトの画面の高さ
#define DEFAULT_COLOR_BITDEPTH						(16)				// デフォルトの色ビット?度

#define DEFAULT_FOV									(60.0F * 3.1415926535897932384626433832795F / 180.0F)	// デフォルトの視野角
#define DEFAULT_TAN_FOV_HALF						(0.57735026918962576450914878050196F) // tan( FOV * 0.5 )
#define DEFAULT_NEAR								(0.0F)				// NEARクリップ面
#define DEFAULT_FAR									(20000.0F)			// FARクリップ面

#define DEFAULT_FONT_SIZE							(16)				// フォントのデフォルトのサイズ
#define DEFAULT_FONT_THINCK							(6)					// フォントのデフォルトの太さ
#define DEFAULT_FONT_TYPE							( DX_FONTTYPE_NORMAL )	// フォントのデフォルトの?態
#define DEFAULT_FONT_EDGESIZE						(1)					// フォントのデフォルトの太さ

#define FONT_CACHE_MAXNUM							(2024)				// フォントキャッシュに格?できる最大文字数
#define FONT_CACHE_MEMORYSIZE						(0x50000)			// フォントキャッシュの最大容量
#define FONT_CACHE_MAX_YLENGTH						(0x4000)			// フォントキャッシュサ?フェスの最大縦幅

#define MAX_USERIMAGEREAD_FUNCNUM					(10)				// ユ?ザ?が登?できるグラフィックロ?ド関数の最大数


// ハンドルの内訳
#define DX_HANDLEINDEX_MASK							(0x0000ffff)		// ハンドル配列インデックス?スク
#define DX_HANDLECHECKBIT_MASK						(0x07ff0000)		// ハンドルインデックスエラ??ェック用?スク
#define DX_HANDLECHECKBIT_ADDRESS					(16)				// ハンドルインデックスエラ??ェック用?スクの開始アドレス
#define DX_HANDLETYPE_MASK							(0x78000000)		// ハンドル?イプ?スク
#define DX_HANDLEERROR_MASK							(0x80000000)		// エラ??ェック?スク( ０ではなかったらエラ? )
#define DX_HANDLEERROR_OR_TYPE_MASK					(0xf8000000)		// DX_HANDLETYPE_MASK と DX_HANDLEERROR_MASK を?け合わせたもの

// ハンドル?イプ定?
#define DX_HANDLETYPE_GRAPH							(0x08000000)		// グラフィックハンドル
#define DX_HANDLETYPE_SOUND							(0x10000000)		// サウンドハンドル
#define DX_HANDLETYPE_MOVIE							(0x18000000)		// ??ビ?ハンドル
#define DX_HANDLETYPE_FONT							(0x20000000)		// フォントハンドル
#define DX_HANDLETYPE_GMASK							(0x28000000)		// ?スクハンドル
#define DX_HANDLETYPE_NETWORK						(0x30000000)		// ネットワ?クハンドル
#define DX_HANDLETYPE_KEYINPUT						(0x38000000)		// 文字列入力ハンドル
#define DX_HANDLETYPE_MUSIC							(0x40000000)		// ?ュ?ジックハンドル
#define DX_HANDLETYPE_LIGHT							(0x48000000)		// ライト
#define DX_HANDLETYPE_MODEL							(0x50000000)		// ３Ｄモデル
#define DX_HANDLETYPE_SOFTIMAGE						(0x58000000)		// ?フトウエアで扱うイメ?ジハンドル
#define DX_HANDLETYPE_SHADER						(0x60000000)		// シェ???ハンドル
#define DX_HANDLETYPE_SOFTSOUND						(0x68000000)		// ?フトサウンドハンドル
#define DX_HANDLETYPE_VERTEX_BUFFER					(0x70000000)		// 頂?バッフ?ハンドル
#define DX_HANDLETYPE_INDEX_BUFFER					(0x78000000)		// インデックスバッフ?ハンドル

// ＷＩＮＤＯＷＳのバ?ジョン?クロ
#define DX_WINDOWSVERSION_31						(0x000)
#define DX_WINDOWSVERSION_95						(0x001)
#define DX_WINDOWSVERSION_98						(0x002)
#define DX_WINDOWSVERSION_ME						(0x003)
#define DX_WINDOWSVERSION_NT31						(0x104)
#define DX_WINDOWSVERSION_NT40						(0x105)
#define DX_WINDOWSVERSION_2000						(0x106)
#define DX_WINDOWSVERSION_XP						(0x107)
#define DX_WINDOWSVERSION_VISTA						(0x108)
#define DX_WINDOWSVERSION_7							(0x109)
#define DX_WINDOWSVERSION_NT_TYPE					(0x100)

// ＤｉｒｅｃｔＸのバ?ジョン?クロ
#define DX_DIRECTXVERSION_NON						(0)
#define DX_DIRECTXVERSION_1							(0x10000)
#define DX_DIRECTXVERSION_2							(0x20000)
#define DX_DIRECTXVERSION_3							(0x30000)
#define DX_DIRECTXVERSION_4							(0x40000)
#define DX_DIRECTXVERSION_5							(0x50000)
#define DX_DIRECTXVERSION_6							(0x60000)
#define DX_DIRECTXVERSION_6_1						(0x60100)
#define DX_DIRECTXVERSION_7							(0x70000)
#define DX_DIRECTXVERSION_8							(0x80000)
#define DX_DIRECTXVERSION_8_1						(0x80100)

// 文字セット
#define DX_CHARSET_DEFAULT							(0)				// デフォルト文字セット
#define DX_CHARSET_SHFTJIS							(1)				// 日?語文字セット
#define DX_CHARSET_HANGEUL							(2)				// 韓国語文字セット
#define DX_CHARSET_BIG5								(3)				// 繁体文字セット
#define DX_CHARSET_GB2312							(4)				// 簡体文字セット

// ＭＩＤＩの再生モ?ド定?
#define DX_MIDIMODE_MCI								(0)				// ＭＣＩによる再生
#define DX_MIDIMODE_DM								(1)				// ＤｉｒｅｃｔＭｕｓｉｃによる再生

// ?画モ?ド定?
#define DX_DRAWMODE_NEAREST							(0)				// ネアレストネイバ??で?画
#define DX_DRAWMODE_BILINEAR						(1)				// バイリニア?で?画する
#define DX_DRAWMODE_ANISOTROPIC						(2)				// 異方性フィル?リング?で?画する
#define DX_DRAWMODE_OTHER							(3)				// それ以外

// フォントの?イプ
#define DX_FONTTYPE_NORMAL							(0)				// ノ??ルフォント
#define DX_FONTTYPE_EDGE							(1)				// エッジつきフォント
#define DX_FONTTYPE_ANTIALIASING					(2)				// アン?エイリアスフォント
#define DX_FONTTYPE_ANTIALIASING_EDGE				(3)				// アン?エイリアス＆エッジ付きフォント

// ?画ブレンドモ?ド定?
#define DX_BLENDMODE_NOBLEND						(0)				// ノ?ブレンド
#define DX_BLENDMODE_ALPHA							(1)				// αブレンド
#define DX_BLENDMODE_ADD							(2)				// 加算ブレンド
#define DX_BLENDMODE_SUB							(3)				// 減算ブレンド
#define DX_BLENDMODE_MUL							(4)				// 乗算ブレンド
   // (内部処理用)
#define DX_BLENDMODE_SUB2							(5)				// 内部処理用減算ブレンド子１
//#define DX_BLENDMODE_BLINEALPHA						(7)				// 境界線ぼかし
#define DX_BLENDMODE_XOR							(6)				// XORブレンド
#define DX_BLENDMODE_DESTCOLOR						(8)				// カラ?は更新されない
#define DX_BLENDMODE_INVDESTCOLOR					(9)				// ?画先の色の反?値を?ける
#define DX_BLENDMODE_INVSRC							(10)			// ?画元の色を反?する
#define DX_BLENDMODE_MULA							(11)			// アルフ??ャンネル考慮付き乗算ブレンド
#define DX_BLENDMODE_ALPHA_X4						(12)			// αブレンドの?画元の輝度を最大４?にできるモ?ド
#define DX_BLENDMODE_ADD_X4							(13)			// 加算ブレンドの?画元の輝度を最大４?にできるモ?ド

// ?リゴンカリングモ?ド
#define DX_CULLING_NONE								(0)				// カリングなし
#define DX_CULLING_LEFT								(1)				// 背面を左回りでカリング
#define DX_CULLING_RIGHT							(2)				// 背面を右回りでカリング

// ?画先画面指定用定?
#define DX_SCREEN_FRONT								(0xfffffffc)
#define DX_SCREEN_BACK								(0xfffffffe) 
#define DX_SCREEN_WORK 								(0xfffffffd)
#define DX_SCREEN_TEMPFRONT							(0xfffffffb)

#define DX_NONE_GRAPH								(0xfffffffb)	// グラフィックなしハンドル

// グラフィック減色時の画像劣化緩和処理モ?ド
#define DX_SHAVEDMODE_NONE							(0)				// 画像劣化緩和処理を行わない
#define DX_SHAVEDMODE_DITHER						(1)				// ディザリング
#define DX_SHAVEDMODE_DIFFUS						(2)				// 誤差拡散

// 画像の保存?イプ
#define DX_IMAGESAVETYPE_BMP						(0)				// bitmap
#define DX_IMAGESAVETYPE_JPEG						(1)				// jpeg
#define DX_IMAGESAVETYPE_PNG						(2)				// Png

// サウンド再生?態指定用定?
#define DX_PLAYTYPE_LOOPBIT							(0x0002)		// ル?プ再生ビット
#define DX_PLAYTYPE_BACKBIT							(0x0001)		// バックグラウンド再生ビット

#define DX_PLAYTYPE_NORMAL							(0)												// ノ??ル再生
#define DX_PLAYTYPE_BACK				  			( DX_PLAYTYPE_BACKBIT )							// バックグラウンド再生
#define DX_PLAYTYPE_LOOP							( DX_PLAYTYPE_LOOPBIT | DX_PLAYTYPE_BACKBIT )	// ル?プ再生

// 動画再生?イプ定?
#define DX_MOVIEPLAYTYPE_BCANCEL					(0)				// ??ンキャンセルあり
#define DX_MOVIEPLAYTYPE_NORMAL						(1)				// ??ンキャンセルなし

// サウンドの?イプ
#define DX_SOUNDTYPE_NORMAL							(0)				// ノ??ルサウンド?式
#define DX_SOUNDTYPE_STREAMSTYLE					(1)				// ストリ??風サウンド?式

// ストリ??サウンド再生デ???イプの?クロ
#define DX_SOUNDDATATYPE_MEMNOPRESS					(0)				// 圧縮された全デ??は再生が始まる前にサウンドメモリにすべて解?され、格?される
#define DX_SOUNDDATATYPE_MEMNOPRESS_PLUS			(1)				// 圧縮された全デ??はシステ?メモリに格?され、再生しながら?次解?され、最終的にすべてサウンドメモリに格?される(その後システ?メモリに存在する圧縮デ??は破棄される)
#define DX_SOUNDDATATYPE_MEMPRESS					(2)				// 圧縮された全デ??はシステ?メモリに格?され、再生する部分だけ?次解?しながらサウンドメモリに格?する(鳴らし終わると解?したデ??は破棄されるので何度も解?処理が行われる)
#define DX_SOUNDDATATYPE_FILE						(3)				// 圧縮されたデ??の再生する部分だけフ?イルから?次読み込み解?され、サウンドメモリに格?される(鳴らし終わると解?したデ??は破棄されるので何度も解?処理が行われる)

// 読み込み処理の?イプ
#define DX_READSOUNDFUNCTION_PCM					(0x0001)		// PCM の読み込み処理
#define DX_READSOUNDFUNCTION_ACM					(0x0002)		// ACM を使用した読み込み処理
#define DX_READSOUNDFUNCTION_OGG					(0x0004)		// Ogg Vorbis の読み込み処理
#define DX_READSOUNDFUNCTION_MP3					(0x0008)		// ACM を使用した MP3 の読み込み処理
#define DX_READSOUNDFUNCTION_DSMP3					(0x0010)		// DirectShow を使用した MP3 の読み込み処理


// ?スク透過色モ?ド
#define DX_MASKTRANS_WHITE							(0)				// ?スク画像の白い部分を透過色とする
#define DX_MASKTRANS_BLACK							(1)				// ?スク画像の黒い部分を透過色とする
#define DX_MASKTRANS_NONE							(2) 			// 透過色なし

// Ｚバッフ?書き込みモ?ド
#define DX_ZWRITE_MASK								(0)				// 書き込めないように?スクする
#define DX_ZWRITE_CLEAR								(1)				// 書き込めるように?スクをクリアする

// 比較モ?ド
#define DX_CMP_NEVER								(1)				// FALSE
#define DX_CMP_LESS									(2)				// Src <  Dest		DrawAlpha <  TestParam
#define DX_CMP_EQUAL								(3)				// Src == Dest		DrawAlpha == TestParam
#define DX_CMP_LESSEQUAL							(4)				// Src <= Dest		DrawAlpha <= TestParam
#define DX_CMP_GREATER								(5)				// Src >  Dest		DrawAlpha >  TestParam
#define DX_CMP_NOTEQUAL								(6)				// Src != Dest		DrawAlpha != TestParam
#define DX_CMP_GREATEREQUAL							(7)				// Src >= Dest		DrawAlpha >= TestParam
#define DX_CMP_ALWAYS								(8)				// TRUE
#define DX_ZCMP_DEFAULT								( DX_CMP_LESSEQUAL )
#define DX_ZCMP_REVERSE								( DX_CMP_GREATEREQUAL )

// シェ?ディングモ?ド
#define DX_SHADEMODE_FLAT							D_D3DSHADE_FLAT
#define DX_SHADEMODE_GOURAUD						D_D3DSHADE_GOURAUD

// フォグモ?ド
#define DX_FOGMODE_NONE								D_D3DFOG_NONE
#define DX_FOGMODE_EXP								D_D3DFOG_EXP
#define DX_FOGMODE_EXP2								D_D3DFOG_EXP2
#define DX_FOGMODE_LINEAR							D_D3DFOG_LINEAR

// ?テリアル?イプ
#define DX_MATERIAL_TYPE_NORMAL						(0)				// 標??テリアル
#define DX_MATERIAL_TYPE_TOON						(1)				// トゥ?ンレン?リング用?テリアル
#define DX_MATERIAL_TYPE_TOON_2						(2)				// トゥ?ンレン?リング用?テリアル_?イプ２( MMD互換 )

// ?テリアルブレンド?イプ
#define DX_MATERIAL_BLENDTYPE_TRANSLUCENT			(0)				// アルフ?合成
#define DX_MATERIAL_BLENDTYPE_ADDITIVE				(1)				// 加算
#define DX_MATERIAL_BLENDTYPE_MODULATE				(2)				// 乗算

// テクス?ャアドレス?イプ
#define DX_TEXADDRESS_WRAP							D_D3DTADDRESS_WRAP
#define DX_TEXADDRESS_MIRROR						D_D3DTADDRESS_MIRROR
#define DX_TEXADDRESS_CLAMP							D_D3DTADDRESS_CLAMP
#define DX_TEXADDRESS_BORDER						D_D3DTADDRESS_BORDER

// 頂?デ???イプ
#define DX_VERTEX_TYPE_NORMAL_3D					(0)				// VERTEX3D?造体?式

// インデックスデ???イプ
#define DX_INDEX_TYPE_16BIT							(0)				// 16bitインデックス

// ?リゴン?画?イプ
#define DX_PRIMTYPE_POINTLIST						D_D3DPT_POINTLIST
#define DX_PRIMTYPE_LINELIST						D_D3DPT_LINELIST
#define DX_PRIMTYPE_LINESTRIP						D_D3DPT_LINESTRIP
#define DX_PRIMTYPE_TRIANGLELIST					D_D3DPT_TRIANGLELIST
#define DX_PRIMTYPE_TRIANGLESTRIP					D_D3DPT_TRIANGLESTRIP
#define DX_PRIMTYPE_TRIANGLEFAN						D_D3DPT_TRIANGLEFAN

// ライト?イプ
#define DX_LIGHTTYPE_D3DLIGHT_POINT					D_D3DLIGHT_POINT
#define DX_LIGHTTYPE_D3DLIGHT_SPOT					D_D3DLIGHT_SPOT
#define DX_LIGHTTYPE_D3DLIGHT_DIRECTIONAL			D_D3DLIGHT_DIRECTIONAL
#define DX_LIGHTTYPE_D3DLIGHT_FORCEDWORD			D_D3DLIGHT_FORCE_DWORD
#define DX_LIGHTTYPE_POINT							D_D3DLIGHT_POINT
#define DX_LIGHTTYPE_SPOT							D_D3DLIGHT_SPOT
#define DX_LIGHTTYPE_DIRECTIONAL					D_D3DLIGHT_DIRECTIONAL

// グラフィックイメ?ジフォ??ットの定?
#define DX_GRAPHICSIMAGE_FORMAT_3D_RGB16					(0)		// １６ビットカラ?標?
#define DX_GRAPHICSIMAGE_FORMAT_3D_RGB32					(1)		// ３２ビットカラ?標?
#define DX_GRAPHICSIMAGE_FORMAT_3D_ALPHA_RGB16				(2)		// α?ャンネル付き１６ビットカラ?
#define DX_GRAPHICSIMAGE_FORMAT_3D_ALPHA_RGB32				(3)		// α?ャンネル付き３２ビットカラ?
#define DX_GRAPHICSIMAGE_FORMAT_3D_ALPHATEST_RGB16			(4)		// αテスト付き１６ビットカラ?
#define DX_GRAPHICSIMAGE_FORMAT_3D_ALPHATEST_RGB32			(5)		// αテスト付き３２ビットカラ?
#define DX_GRAPHICSIMAGE_FORMAT_3D_DXT1						(6)		// ＤＸＴ１
#define DX_GRAPHICSIMAGE_FORMAT_3D_DXT2						(7)		// ＤＸＴ２
#define DX_GRAPHICSIMAGE_FORMAT_3D_DXT3						(8)		// ＤＸＴ３
#define DX_GRAPHICSIMAGE_FORMAT_3D_DXT4						(9)		// ＤＸＴ４
#define DX_GRAPHICSIMAGE_FORMAT_3D_DXT5 					(10)	// ＤＸＴ５
#define DX_GRAPHICSIMAGE_FORMAT_3D_DRAWVALID_RGB16			(11)	// ?画可?１６ビットカラ?
#define DX_GRAPHICSIMAGE_FORMAT_3D_DRAWVALID_RGB32			(12)	// ?画可?３２ビットカラ?
#define DX_GRAPHICSIMAGE_FORMAT_3D_DRAWVALID_ALPHA_RGB32	(13)	// ?画可?α付き３２ビットカラ?
#define DX_GRAPHICSIMAGE_FORMAT_3D_NUM						(14)
#define DX_GRAPHICSIMAGE_FORMAT_2D							(14)	// 標?( DirectDrawSurface の場合はこれのみ )
#define DX_GRAPHICSIMAGE_FORMAT_R5G6B5						(15)	// R5G6B5( MEMIMG 用 )
#define DX_GRAPHICSIMAGE_FORMAT_X8A8R5G6B5					(16)	// X8A8R5G6B5( MEMIMG 用 )
#define DX_GRAPHICSIMAGE_FORMAT_X8R8G8B8					(17)	// X8R8G8B8( MEMIMG 用 )
#define DX_GRAPHICSIMAGE_FORMAT_A8R8G8B8					(18)	// A8R8G8B8( MEMIMG 用 )

#define DX_GRAPHICSIMAGE_FORMAT_NUM							(19)	// グラフィックフォ??ットの種類の数

// 基?イメ?ジのピクセルフォ??ット
#define DX_BASEIMAGE_FORMAT_NORMAL			(0)			// 普通の画像
#define DX_BASEIMAGE_FORMAT_DXT1			(1)			// ＤＸＴ１
#define DX_BASEIMAGE_FORMAT_DXT2			(2)			// ＤＸＴ２
#define DX_BASEIMAGE_FORMAT_DXT3			(3)			// ＤＸＴ３
#define DX_BASEIMAGE_FORMAT_DXT4			(4)			// ＤＸＴ４
#define DX_BASEIMAGE_FORMAT_DXT5			(5)			// ＤＸＴ５

// ツ?ルバ?の??ンの状態
#define TOOLBUTTON_STATE_ENABLE				(0)			// 入力可?な状態
#define TOOLBUTTON_STATE_PRESSED			(1)			// 押されている状態
#define TOOLBUTTON_STATE_DISABLE			(2)			// 入力不可?な状態
#define TOOLBUTTON_STATE_PRESSED_DISABLE	(3)			// 押されている状態で、入力不可?な状態
#define TOOLBUTTON_STATE_NUM				(4)			// ツ?ルバ?の??ンの状態の数

// ツ?ルバ?の??ンの?イプ
#define TOOLBUTTON_TYPE_NORMAL			(0)			// 普通の??ン
#define TOOLBUTTON_TYPE_CHECK			(1)			// 押すごとにＯＮ?ＯＦＦが切り替わる??ン
#define TOOLBUTTON_TYPE_GROUP			(2)			// 別の TOOLBUTTON_TYPE_GROUP ?イプの??ンが押されるとＯＦＦになる?イプの??ン(グル?プの区切りは隙間で)
#define TOOLBUTTON_TYPE_SEP				(3)			// 隙間(??ンではありません)
#define TOOLBUTTON_TYPE_NUM				(4)			// ツ?ルバ?の??ンの?イプの数

// 親メニュ?のＩＤ
#define MENUITEM_IDTOP								(0xabababab)

// メニュ?に追加する際の?イプ
#define MENUITEM_ADD_CHILD							(0)				// 指定の?目の子として追加する
#define MENUITEM_ADD_INSERT							(1)				// 指定の?目と指定の?目より一つ上の?目の間に追加する

// メニュ?の横に付く??ク?イプ
#define MENUITEM_MARK_NONE							(0)				// 何も付け無い
#define MENUITEM_MARK_CHECK							(1)				// ?ェック??ク
#define MENUITEM_MARK_RADIO							(2)				// ラジオ??ン

// 文字変換?イプ定?
#define DX_NUMMODE_10								(0)				// １０進数
#define DX_NUMMODE_16								(1)				// １６進数
#define DX_STRMODE_NOT0								(2)				// 空きを０で埋めない
#define DX_STRMODE_USE0								(3)				// 空きを０で埋める

// CheckHitKeyAll で調べる入力?イプ
#define DX_CHECKINPUT_KEY							(0x0001)		// キ?入力を調べる
#define DX_CHECKINPUT_PAD							(0x0002)		// パッド入力を調べる
#define DX_CHECKINPUT_MOUSE							(0x0004)		// ?ウス??ン入力を調べる
#define DX_CHECKINPUT_ALL							(DX_CHECKINPUT_KEY | DX_CHECKINPUT_PAD | DX_CHECKINPUT_MOUSE)	// すべての入力を調べる

// パッド入力取得パラメ??
#define DX_INPUT_KEY_PAD1							(0x1001)		// キ?入力とパッド１入力
#define DX_INPUT_PAD1								(0x0001)		// パッド１入力
#define DX_INPUT_PAD2								(0x0002)		// パッド２入力
#define DX_INPUT_PAD3								(0x0003)		// パッド３入力
#define DX_INPUT_PAD4								(0x0004)		// パッド４入力
#define DX_INPUT_PAD5								(0x0005)		// パッド５入力
#define DX_INPUT_PAD6								(0x0006)		// パッド６入力
#define DX_INPUT_PAD7								(0x0007)		// パッド７入力
#define DX_INPUT_PAD8								(0x0008)		// パッド８入力
#define DX_INPUT_PAD9								(0x0009)		// パッド９入力
#define DX_INPUT_PAD10								(0x000a)		// パッド１０入力
#define DX_INPUT_PAD11								(0x000b)		// パッド１１入力
#define DX_INPUT_PAD12								(0x000c)		// パッド１２入力
#define DX_INPUT_PAD13								(0x000d)		// パッド１３入力
#define DX_INPUT_PAD14								(0x000e)		// パッド１４入力
#define DX_INPUT_PAD15								(0x000f)		// パッド１５入力
#define DX_INPUT_PAD16								(0x0010)		// パッド１６入力
#define DX_INPUT_KEY								(0x1000)		// キ?入力

// ??ビ?のサ?フェスモ?ド
#define DX_MOVIESURFACE_NORMAL						(0)
#define DX_MOVIESURFACE_OVERLAY						(1)
#define DX_MOVIESURFACE_FULLCOLOR					(2)

// パッド入力定?
#define PAD_INPUT_DOWN								(0x00000001)	// ↓?ェック?スク
#define PAD_INPUT_LEFT								(0x00000002)	// ←?ェック?スク
#define PAD_INPUT_RIGHT								(0x00000004)	// →?ェック?スク
#define PAD_INPUT_UP								(0x00000008)	// ↑?ェック?スク
#define PAD_INPUT_A									(0x00000010)	// ???ン?ェック?スク
#define PAD_INPUT_B									(0x00000020)	// Ｂ??ン?ェック?スク
#define PAD_INPUT_C									(0x00000040)	// Ｃ??ン?ェック?スク
#define PAD_INPUT_X									(0x00000080)	// Ｘ??ン?ェック?スク
#define PAD_INPUT_Y									(0x00000100)	// Ｙ??ン?ェック?スク
#define PAD_INPUT_Z									(0x00000200)	// Ｚ??ン?ェック?スク
#define PAD_INPUT_L									(0x00000400)	// Ｌ??ン?ェック?スク
#define PAD_INPUT_R									(0x00000800)	// Ｒ??ン?ェック?スク
#define PAD_INPUT_START								(0x00001000)	// ＳＴ?ＲＴ??ン?ェック?スク
#define PAD_INPUT_M									(0x00002000)	// Ｍ??ン?ェック?スク
#define PAD_INPUT_D									(0x00004000)
#define PAD_INPUT_F									(0x00008000)
#define PAD_INPUT_G									(0x00010000)
#define PAD_INPUT_H									(0x00020000)
#define PAD_INPUT_I									(0x00040000)
#define PAD_INPUT_J									(0x00080000)
#define PAD_INPUT_K									(0x00100000)
#define PAD_INPUT_LL								(0x00200000)
#define PAD_INPUT_N									(0x00400000)
#define PAD_INPUT_O									(0x00800000)
#define PAD_INPUT_P									(0x01000000)
#define PAD_INPUT_RR								(0x02000000)
#define PAD_INPUT_S									(0x04000000)
#define PAD_INPUT_T									(0x08000000)
#define PAD_INPUT_U									(0x10000000)
#define PAD_INPUT_V									(0x20000000)
#define PAD_INPUT_W									(0x40000000)
#define PAD_INPUT_XX								(0x80000000)

#define PAD_INPUT_1									(0x00000010)
#define PAD_INPUT_2									(0x00000020)
#define PAD_INPUT_3									(0x00000040)
#define PAD_INPUT_4									(0x00000080)
#define PAD_INPUT_5									(0x00000100)
#define PAD_INPUT_6									(0x00000200)
#define PAD_INPUT_7									(0x00000400)
#define PAD_INPUT_8									(0x00000800)
#define PAD_INPUT_9									(0x00001000)
#define PAD_INPUT_10								(0x00002000)
#define PAD_INPUT_11								(0x00004000)
#define PAD_INPUT_12								(0x00008000)
#define PAD_INPUT_13								(0x00010000)
#define PAD_INPUT_14								(0x00020000)
#define PAD_INPUT_15								(0x00040000)
#define PAD_INPUT_16								(0x00080000)
#define PAD_INPUT_17								(0x00100000)
#define PAD_INPUT_18								(0x00200000)
#define PAD_INPUT_19								(0x00400000)
#define PAD_INPUT_20								(0x00800000)
#define PAD_INPUT_21								(0x01000000)
#define PAD_INPUT_22								(0x02000000)
#define PAD_INPUT_23								(0x04000000)
#define PAD_INPUT_24								(0x08000000)
#define PAD_INPUT_25								(0x10000000)
#define PAD_INPUT_26								(0x20000000)
#define PAD_INPUT_27								(0x40000000)
#define PAD_INPUT_28								(0x80000000)

// ?ウス入力定?
#define MOUSE_INPUT_LEFT							(0x0001)			// ?ウス左??ン
#define MOUSE_INPUT_RIGHT							(0x0002)			// ?ウス右??ン
#define MOUSE_INPUT_MIDDLE							(0x0004)			// ?ウス中央??ン
#define MOUSE_INPUT_1								(0x0001)			// ?ウス１??ン
#define MOUSE_INPUT_2								(0x0002)			// ?ウス２??ン
#define MOUSE_INPUT_3								(0x0004)			// ?ウス３??ン
#define MOUSE_INPUT_4								(0x0008)			// ?ウス４??ン
#define MOUSE_INPUT_5								(0x0010)			// ?ウス５??ン
#define MOUSE_INPUT_6								(0x0020)			// ?ウス６??ン
#define MOUSE_INPUT_7								(0x0040)			// ?ウス７??ン
#define MOUSE_INPUT_8								(0x0080)			// ?ウス８??ン

// キ?定?
#define KEY_INPUT_BACK								D_DIK_BACK			// バックスペ?スキ?
#define KEY_INPUT_TAB								D_DIK_TAB			// ?ブキ?
#define KEY_INPUT_RETURN							D_DIK_RETURN		// エン??キ?

#define KEY_INPUT_LSHIFT							D_DIK_LSHIFT		// 左シフトキ?
#define KEY_INPUT_RSHIFT							D_DIK_RSHIFT		// 右シフトキ?
#define KEY_INPUT_LCONTROL							D_DIK_LCONTROL		// 左コントロ?ルキ?
#define KEY_INPUT_RCONTROL							D_DIK_RCONTROL		// 右コントロ?ルキ?
#define KEY_INPUT_ESCAPE							D_DIK_ESCAPE		// エスケ?プキ?
#define KEY_INPUT_SPACE								D_DIK_SPACE			// スペ?スキ?
#define KEY_INPUT_PGUP								D_DIK_PGUP			// ＰａｇｅＵＰキ?
#define KEY_INPUT_PGDN								D_DIK_PGDN			// ＰａｇｅＤｏｗｎキ?
#define KEY_INPUT_END								D_DIK_END			// エンドキ?
#define KEY_INPUT_HOME								D_DIK_HOME			// ホ??キ?
#define KEY_INPUT_LEFT								D_DIK_LEFT			// 左キ?
#define KEY_INPUT_UP								D_DIK_UP			// 上キ?
#define KEY_INPUT_RIGHT								D_DIK_RIGHT			// 右キ?
#define KEY_INPUT_DOWN								D_DIK_DOWN			// 下キ?
#define KEY_INPUT_INSERT							D_DIK_INSERT		// インサ?トキ?
#define KEY_INPUT_DELETE							D_DIK_DELETE		// デリ?トキ?

#define KEY_INPUT_MINUS								D_DIK_MINUS			// ?キ?
#define KEY_INPUT_YEN								D_DIK_YEN			// ￥キ?
#define KEY_INPUT_PREVTRACK							D_DIK_PREVTRACK		// ＾キ?
#define KEY_INPUT_PERIOD							D_DIK_PERIOD		// ．キ?
#define KEY_INPUT_SLASH								D_DIK_SLASH			// ?キ?
#define KEY_INPUT_LALT								D_DIK_LALT			// 左?ＬＴキ?
#define KEY_INPUT_RALT								D_DIK_RALT			// 右?ＬＴキ?
#define KEY_INPUT_SCROLL							D_DIK_SCROLL		// ScrollLockキ?
#define KEY_INPUT_SEMICOLON							D_DIK_SEMICOLON		// ；キ?
#define KEY_INPUT_COLON								D_DIK_COLON			// ：キ?
#define KEY_INPUT_LBRACKET							D_DIK_LBRACKET		// ［キ?
#define KEY_INPUT_RBRACKET							D_DIK_RBRACKET		// ］キ?
#define KEY_INPUT_AT								D_DIK_AT			// ＠キ?
#define KEY_INPUT_BACKSLASH							D_DIK_BACKSLASH		// ?キ?
#define KEY_INPUT_COMMA								D_DIK_COMMA			// ，キ?
#define KEY_INPUT_KANJI								D_DIK_KANJI			// 漢字キ?
#define KEY_INPUT_CONVERT							D_DIK_CONVERT		// 変換キ?
#define KEY_INPUT_NOCONVERT							D_DIK_NOCONVERT		// 無変換キ?
#define KEY_INPUT_KANA								D_DIK_KANA			// カナキ?
#define KEY_INPUT_APPS								D_DIK_APPS			// アプリケ?ションメニュ?キ?
#define KEY_INPUT_CAPSLOCK							D_DIK_CAPSLOCK		// CaspLockキ?
#define KEY_INPUT_SYSRQ								D_DIK_SYSRQ			// PrintScreenキ?
#define KEY_INPUT_PAUSE								D_DIK_PAUSE			// PauseBreakキ?
#define KEY_INPUT_LWIN								D_DIK_LWIN			// 左Ｗｉｎキ?
#define KEY_INPUT_RWIN								D_DIK_RWIN			// 右Ｗｉｎキ?

#define KEY_INPUT_NUMLOCK							D_DIK_NUMLOCK		// テンキ?０
#define KEY_INPUT_NUMPAD0							D_DIK_NUMPAD0		// テンキ?０
#define KEY_INPUT_NUMPAD1							D_DIK_NUMPAD1		// テンキ?１
#define KEY_INPUT_NUMPAD2							D_DIK_NUMPAD2		// テンキ?２
#define KEY_INPUT_NUMPAD3							D_DIK_NUMPAD3		// テンキ?３
#define KEY_INPUT_NUMPAD4							D_DIK_NUMPAD4		// テンキ?４
#define KEY_INPUT_NUMPAD5							D_DIK_NUMPAD5		// テンキ?５
#define KEY_INPUT_NUMPAD6							D_DIK_NUMPAD6		// テンキ?６
#define KEY_INPUT_NUMPAD7							D_DIK_NUMPAD7		// テンキ?７
#define KEY_INPUT_NUMPAD8							D_DIK_NUMPAD8		// テンキ?８
#define KEY_INPUT_NUMPAD9							D_DIK_NUMPAD9		// テンキ?９
#define KEY_INPUT_MULTIPLY							D_DIK_MULTIPLY		// テンキ?＊キ?
#define KEY_INPUT_ADD								D_DIK_ADD			// テンキ??キ?
#define KEY_INPUT_SUBTRACT							D_DIK_SUBTRACT		// テンキ??キ?
#define KEY_INPUT_DECIMAL							D_DIK_DECIMAL		// テンキ?．キ?
#define KEY_INPUT_DIVIDE							D_DIK_DIVIDE		// テンキ??キ?
#define KEY_INPUT_NUMPADENTER						D_DIK_NUMPADENTER	// テンキ?のエン??キ?

#define KEY_INPUT_F1								D_DIK_F1			// Ｆ１キ?
#define KEY_INPUT_F2								D_DIK_F2			// Ｆ２キ?
#define KEY_INPUT_F3								D_DIK_F3			// Ｆ３キ?
#define KEY_INPUT_F4								D_DIK_F4			// Ｆ４キ?
#define KEY_INPUT_F5								D_DIK_F5			// Ｆ５キ?
#define KEY_INPUT_F6								D_DIK_F6			// Ｆ６キ?
#define KEY_INPUT_F7								D_DIK_F7			// Ｆ７キ?
#define KEY_INPUT_F8								D_DIK_F8			// Ｆ８キ?
#define KEY_INPUT_F9								D_DIK_F9			// Ｆ９キ?
#define KEY_INPUT_F10								D_DIK_F10			// Ｆ１０キ?
#define KEY_INPUT_F11								D_DIK_F11			// Ｆ１１キ?
#define KEY_INPUT_F12								D_DIK_F12			// Ｆ１２キ?

#define KEY_INPUT_A									D_DIK_A			// ?キ?
#define KEY_INPUT_B									D_DIK_B			// Ｂキ?
#define KEY_INPUT_C									D_DIK_C			// Ｃキ?
#define KEY_INPUT_D									D_DIK_D			// Ｄキ?
#define KEY_INPUT_E									D_DIK_E			// Ｅキ?
#define KEY_INPUT_F									D_DIK_F			// Ｆキ?
#define KEY_INPUT_G									D_DIK_G			// Ｇキ?
#define KEY_INPUT_H									D_DIK_H			// Ｈキ?
#define KEY_INPUT_I									D_DIK_I			// Ｉキ?
#define KEY_INPUT_J									D_DIK_J			// Ｊキ?
#define KEY_INPUT_K									D_DIK_K			// Ｋキ?
#define KEY_INPUT_L									D_DIK_L			// Ｌキ?
#define KEY_INPUT_M									D_DIK_M			// Ｍキ?
#define KEY_INPUT_N									D_DIK_N			// Ｎキ?
#define KEY_INPUT_O									D_DIK_O			// Ｏキ?
#define KEY_INPUT_P									D_DIK_P			// Ｐキ?
#define KEY_INPUT_Q									D_DIK_Q			// Ｑキ?
#define KEY_INPUT_R									D_DIK_R			// Ｒキ?
#define KEY_INPUT_S									D_DIK_S			// Ｓキ?
#define KEY_INPUT_T									D_DIK_T			// Ｔキ?
#define KEY_INPUT_U									D_DIK_U			// Ｕキ?
#define KEY_INPUT_V									D_DIK_V			// Ｖキ?
#define KEY_INPUT_W									D_DIK_W			// Ｗキ?
#define KEY_INPUT_X									D_DIK_X			// Ｘキ?
#define KEY_INPUT_Y									D_DIK_Y			// Ｙキ?
#define KEY_INPUT_Z									D_DIK_Z			// Ｚキ?

#define KEY_INPUT_0 								D_DIK_0			// ０キ?
#define KEY_INPUT_1									D_DIK_1			// １キ?
#define KEY_INPUT_2									D_DIK_2			// ２キ?
#define KEY_INPUT_3									D_DIK_3			// ３キ?
#define KEY_INPUT_4									D_DIK_4			// ４キ?
#define KEY_INPUT_5									D_DIK_5			// ５キ?
#define KEY_INPUT_6									D_DIK_6			// ６キ?
#define KEY_INPUT_7									D_DIK_7			// ７キ?
#define KEY_INPUT_8									D_DIK_8			// ８キ?
#define KEY_INPUT_9									D_DIK_9			// ９キ?

// アスキ?コントロ?ルキ?コ?ド
#define CTRL_CODE_BS								(0x08)				// バックスペ?ス
#define CTRL_CODE_TAB								(0x09)				// ?ブ
#define CTRL_CODE_CR								(0x0d)				// 改行
#define CTRL_CODE_DEL								(0x10)				// ＤＥＬキ?

#define CTRL_CODE_COPY								(0x03)				// コピ?
#define CTRL_CODE_PASTE								(0x16)				// ペ?スト
#define CTRL_CODE_CUT								(0x18)				// カット
#define CTRL_CODE_ALL								(0x01)				// 全て選択

#define CTRL_CODE_LEFT								(0x1d)				// ←キ?
#define CTRL_CODE_RIGHT								(0x1c)				// →キ?
#define CTRL_CODE_UP								(0x1e)				// ↑キ?
#define CTRL_CODE_DOWN								(0x1f)				// ↓キ?

#define CTRL_CODE_HOME								(0x1a)				// ＨＯＭＥ??ン
#define CTRL_CODE_END								(0x19)				// ＥＮＤ??ン
#define CTRL_CODE_PAGE_UP							(0x17)				// Ｐ?ＧＥ ＵＰ
#define CTRL_CODE_PAGE_DOWN							(0x15)				// Ｐ?ＧＥ ＤＯＷＮ

#define CTRL_CODE_ESC								(0x1b)				// ＥＳＣキ?
#define CTRL_CODE_CMP								(0x20)				// 制御コ?ド?居値

// SetGraphMode 戻り値定?
#define DX_CHANGESCREEN_OK							(0)					// 画面変更は成功した
#define DX_CHANGESCREEN_RETURN						(-1)				// 画面の変更は失敗し、元の画面モ?ドに戻された
#define DX_CHANGESCREEN_DEFAULT						(-2)				// 画面の変更は失敗しデフォルトの画面モ?ドに変更された
#define DX_CHANGESCREEN_REFRESHNORMAL				(-3)				// 画面の変更は成功したが、リフレッシュレ?トの変更は失敗した

// ストリ??デ??読み込み処理コ?ド簡略化関連
#define STTELL( st )								((st)->ReadShred.Tell( (st)->DataPoint ))
#define STSEEK( st, pos, type )						((st)->ReadShred.Seek( (st)->DataPoint, (pos), (type) ))
#define STREAD( buf, length, num, st )				((st)->ReadShred.Read( (buf), (length), (num), (st)->DataPoint ))
#define STWRITE( buf, length, num, st )				((st)->ReadShred.Write( (buf), (length), (num), (st)->DataPoint ))
#define STEOF( st )									((st)->ReadShred.Eof( (st)->DataPoint ))
#define STCLOSE( st )								((st)->ReadShred.Close( (st)->DataPoint ))

// ストリ??デ??制御のシ?ク?イプ定?
#define STREAM_SEEKTYPE_SET							(SEEK_SET)
#define STREAM_SEEKTYPE_END							(SEEK_END)
#define STREAM_SEEKTYPE_CUR							(SEEK_CUR)

// グラフィックロ?ド時のイメ?ジ?イプ
#define LOADIMAGE_TYPE_FILE							(0)				// イメ?ジはフ?イルである
#define LOADIMAGE_TYPE_MEM							(1)				// イメ?ジはメモリである
#define LOADIMAGE_TYPE_NONE							(-1)			// イメ?ジは無い

// DrawPreparation 関数に渡すフラグ
#define DRAWPREP_TRANS			(0x0001)
#define DRAWPREP_VECTORINT		(0x0002)
#define DRAWPREP_GOURAUDSHADE	(0x0008)
#define DRAWPREP_PERSPECTIVE	(0x0010)
#define DRAWPREP_DIFFUSERGB		(0x0020)
#define DRAWPREP_DIFFUSEALPHA	(0x0040)
#define DRAWPREP_FOG			(0x0080)
#define DRAWPREP_NOBLENDSETTING	(0x0100)
#define DRAWPREP_LIGHTING		(0x0200)
#define DRAWPREP_SPECULAR		(0x0400)
#define DRAWPREP_3D				(0x0800)
#define DRAWPREP_TEXADDRESS		(0x1000)
#define DRAWPREP_NOTSHADERRESET	(0x2000)


#ifndef DX_NON_NETWORK

// HTTP エラ?
#define HTTP_ERR_SERVER								(0)				// サ?バ?エラ?
#define HTTP_ERR_NOTFOUND							(1)				// フ?イルが見つからなかった
#define HTTP_ERR_MEMORY								(2)				// メモリ確保の失敗
#define HTTP_ERR_LOST								(3)				// 途中で切断された
#define HTTP_ERR_NONE								(-1)			// エラ?は報告されていない

// HTTP 処理の結果
#define HTTP_RES_COMPLETE							(0)				// 処理完了
#define HTTP_RES_STOP								(1)				// 処理中?
#define HTTP_RES_ERROR								(2)				// エラ?終了
#define HTTP_RES_NOW								(-1)			// 現在進行中

#endif

#define DX_DEFINE_END

// デ???定?-------------------------------------------------------------------

namespace DxLib
{

#define DX_STRUCT_START

// ＩＭＥ入力文字列の?画に必要な情報の内の文節情報
typedef struct tagIMEINPUTCLAUSEDATA
{
	int						Position ;				// 何バイト目から
	int						Length ;				// 何バイトか
} IMEINPUTCLAUSEDATA, *LPIMEINPUTCLAUSEDATA ;

// ＩＭＥ入力文字列の?画に必要な情報
typedef struct tagIMEINPUTDATA
{
	const TCHAR *				InputString ;			// 入力中の文字列

	int							CursorPosition ;		// カ??ルの入力文字列中の位置(バイト単位)

	const IMEINPUTCLAUSEDATA *	ClauseData ;			// 文節情報
	int							ClauseNum ;				// 文節情報の数
	int							SelectClause ;			// 選択中の分節( -1 の場合はどの文節にも属していない( 末尾にカ??ルがある ) )

	int							CandidateNum ;			// 変換候補の数( 0の場合は変換中ではない )
	const TCHAR **				CandidateList ;			// 変換候補文字列リスト( 例：ｎ番目の候補を?画する場合  DrawString( 0, 0, data.CandidateList[ n ], GetColor(255,255,255) ); )
	int							SelectCandidate ;		// 選択中の変換候補

	int							ConvertFlag ;			// 文字変換中かどうか( TRUE:変換中  FALSE:変換中ではない( 文字単位でカ??ルが移動できる状態 ) )
} IMEINPUTDATA, *LPIMEINPUTDATA ;

// ?イ?デ???
typedef struct tagDATEDATA
{
	int						Year ;							// 年
	int						Mon ;							// 月
	int						Day ;							// 日
	int						Hour ;							// 時間
	int						Min ;							// 分
	int						Sec ;							// 秒
} DATEDATA, *LPDATEDATA ;

// 画面モ?ド情報デ???
typedef struct tagDISPLAYMODEDATA
{
	int						Width ;				// 水平解像度
	int						Height ;			// 垂直解像度
	int						ColorBitDepth ;		// 色ビット?度
	int						RefreshRate ;		// リフレッシュレ?ト( -1 の場合は規定値 )
} DISPLAYMODEDATA, *LPDISPLAYMODEDATA ;

// フ?イル情報?造体
typedef struct tagFILEINFO
{
	TCHAR					Name[260] ;			 // オブジェクト名
	int						DirFlag ;			// ディレクトリかどうか( TRUE:ディレクトリ  FALSE:フ?イル )
	LONGLONG				Size ;				// サイズ
	DATEDATA				CreationTime ;		// 作成時刻
	DATEDATA				LastWriteTime ;		// 最終更新時刻
} FILEINFO, *LPFILEINFO ;

#ifndef DX_NOTUSE_DRAWFUNCTION

// 行列?造体
typedef struct tagMATRIX
{
	float					m[4][4] ;
} MATRIX, *LPMATRIX ;

// ベクトルデ???
typedef struct tagVECTOR
{
	float					x, y, z ;
} VECTOR, *LPVECTOR, XYZ, *LPXYZ ;

// FLOAT2個デ???
typedef struct tagFLOAT2
{
	float					u, v ;
} UV ;

// float ?のカラ?値
typedef struct tagCOLOR_F
{
	float					r, g, b, a ;
} COLOR_F, *LPCOLOR_F ;

// unsigned char ?のカラ?値
typedef struct tagCOLOR_U8
{
	BYTE					b, g, r, a ;
} COLOR_U8 ;

// FLOAT4個デ???
typedef struct tagFLOAT4
{
	float					x, y, z, w ;
} FLOAT4, *LPFLOAT4 ;

// INT4個デ???
typedef struct tagINT4
{
	int						x, y, z, w ;
} INT4 ;

// ２Ｄ?画用頂??造体(テクス?ャ無し)
typedef struct tagVERTEX_NOTEX_2D
{
	VECTOR					pos ;
	float					rhw ;
	int						color ;
} VERTEX_NOTEX_2D, *LPVERTEX_NOTEX_2D ; 

// 主に２Ｄ?画に使用する頂?デ???
typedef struct tagVERTEX_2D
{
	VECTOR					pos ;
	float					rhw ;
	int						color ;
	float					u, v ;
} VERTEX_2D, *LPVERTEX_2D ; 

// ２Ｄ?画に使用する頂?デ???(DrawPrimitive2D用)
typedef struct tagVERTEX2D
{
	VECTOR					pos ;
	float					rhw ;
	COLOR_U8				dif ;
	float					u, v ;
} VERTEX2D, *LPVERTEX2D ; 

// ２Ｄ?画に使用する頂?デ???(DrawPrimitive2DToShader用)
typedef struct tagVERTEX2DSHADER
{
	VECTOR					pos ;
	float					rhw ;
	COLOR_U8				dif ;
	COLOR_U8				spc ;
	float					u, v ;
	float					su, sv ;
} VERTEX2DSHADER, *LPVERTEX2DSHADER ; 

// ２Ｄ?画に使用する頂?デ???(公開用)
typedef struct tagVERTEX
{
	float					x, y ;
	float					u, v ;
	unsigned char			b, g, r, a ;
} VERTEX ;

// ３Ｄ?画に使用する頂?デ???( テクス?ャなし )( 旧バ?ジョンのもの )
typedef struct tagVERTEX_NOTEX_3D
{
	VECTOR					pos ;
	unsigned char			b, g, r, a ;
} VERTEX_NOTEX_3D, *LPVERTEX_NOTEX_3D ;

// ３Ｄ?画に使用する頂?デ???( 旧バ?ジョンのもの )
typedef struct tagVERTEX_3D
{
	VECTOR					pos ;
	unsigned char			b, g, r, a ;
	float					u, v ;
} VERTEX_3D, *LPVERTEX_3D ;

// ３Ｄ?画に使用する頂?デ???
typedef struct tagVERTEX3D
{
	VECTOR					pos ;
	VECTOR					norm ;
	COLOR_U8				dif ;
	COLOR_U8				spc ;
	float					u, v ;
	float					su, sv ;
} VERTEX3D, *LPVERTEX3D ;

// ３Ｄ?画に使用する頂?デ???( DrawPrimitive3DToShader用 )
// 注意…メンバ変数に追加があるかもしれませんので、宣言時の初期化( VERTEX3DSHADER Vertex = { 0.0f, 0.0f, ... というようなもの )はしない方が良いです
typedef struct tagVERTEX3DSHADER
{
	VECTOR					pos ;
	VECTOR					norm ;
	COLOR_U8				dif ;
	COLOR_U8				spc ;
	float					u, v ;
	float					su, sv ;
} VERTEX3DSHADER, *LPVERTEX3DSHADER ;

// ライトパラメ??
typedef struct tagLIGHTPARAM
{
	int						LightType ;					// ライトの?イプ( DX_LIGHTTYPE_D3DLIGHT_POINT 等 )
	COLOR_F					Diffuse ;					// ディフュ?ズカラ?
	COLOR_F					Specular ;					// スペキュラカラ?
	COLOR_F					Ambient ;					// アンビエント色
	VECTOR					Position ;					// 位置
	VECTOR					Direction ;					// 方向
	float					Range ;						// 有効距離
	float					Falloff ;					// フォ?ルオフ 1.0f にしておくのが好ましい
	float					Attenuation0 ;				// 距離による減衰係数０
	float					Attenuation1 ;				// 距離による減衰係数１
	float					Attenuation2 ;				// 距離による減衰係数２
	float					Theta ;						// ス?ットライトの内部コ?ンの照明角度( ラジアン )
	float					Phi ;						// ス?ットライトの外部コ?ンの照明角度
} LIGHTPARAM ;

// ?テリアルパラメ??
typedef struct tagMATERIALPARAM
{
	COLOR_F					Diffuse ;					// ディフュ?ズカラ?
	COLOR_F					Ambient ;					// アンビエントカラ?
	COLOR_F					Specular ;					// スペキュラカラ?
	COLOR_F					Emissive ;					// エ?ッシブカラ?
	float					Power ;						// スペキュラハイライトの鮮明度
} MATERIALPARAM ;

// ラインヒット?ェック結果格?用?造体
typedef struct tagHITRESULT_LINE
{
	int						HitFlag ;					// 当たったかどうか( 1:当たった  0:当たらなかった )
	VECTOR					Position ;					// 当たった座標
} HITRESULT_LINE ;

// コリジョン結果代入用?リゴン
typedef struct tagMV1_COLL_RESULT_POLY
{
	int						HitFlag ;							// ( MV1CollCheck_Line でのみ有効 )ヒットフラグ( 1:ヒットした  0:ヒットしなかった )
	VECTOR					HitPosition ;						// ( MV1CollCheck_Line でのみ有効 )ヒット座標

	int						FrameIndex ;						// 当たった?リゴンが含まれるフレ??の番号
	int						PolygonIndex ;						// 当たった?リゴンの番号
	int						MaterialIndex ;						// 当たった?リゴンが使用している?テリアルの番号
	VECTOR					Position[ 3 ] ;						// 当たった?リゴンを?成する三?の座標
	VECTOR					Normal ;							// 当たった?リゴンの?線
} MV1_COLL_RESULT_POLY ;

// コリジョン結果代入用?リゴン配列
typedef struct tagMV1_COLL_RESULT_POLY_DIM
{
	int						HitNum ;							// ヒットした?リゴンの数
	MV1_COLL_RESULT_POLY *	Dim ;								// ヒットした?リゴンの配列( HitNum個分存在する )
} MV1_COLL_RESULT_POLY_DIM ;

// 参照用頂??造体
typedef struct tagMV1_REF_VERTEX
{
	VECTOR					Position ;							// 位置
	VECTOR					Normal ;							// ?線
	UV						TexCoord[ 2 ] ;						// テクス?ャ座標
	COLOR_U8				DiffuseColor ;						// ディフュ?ズカラ?
	COLOR_U8				SpecularColor ;						// スペキュラカラ?
} MV1_REF_VERTEX ;

// 参照用?リゴン?造体
typedef struct tagMV1_REF_POLYGON
{
	unsigned short			FrameIndex ;						// この?リゴンが属しているフレ??
	unsigned short			MaterialIndex ;						// 使用している?テリアル
	int						VIndexTarget ;						// VIndex が指すインデックスの参照先( 1:フレ??  0:モデル全体 )
	int						VIndex[ 3 ] ;						// ３角??リゴンを成す参照頂?のインデックス
	VECTOR					MinPosition ;						// ?リゴンを成す頂?座標の最小値
	VECTOR					MaxPosition ;						// ?リゴンを成す頂?座標の最大値
} MV1_REF_POLYGON ;

// 参照用?リゴンデ???造体
typedef struct tagMV1_REF_POLYGONLIST
{
	int						PolygonNum ;						// 参照用?リゴンの数
	int						VertexNum ;							// 頂?の数
	VECTOR					MinPosition ;						// 頂?座標の最小値
	VECTOR					MaxPosition ;						// 頂?座標の最大値
	MV1_REF_POLYGON	*		Polygons ;							// 参照用?リゴン配列
	MV1_REF_VERTEX *		Vertexs ;							// 参照用頂?配列
} MV1_REF_POLYGONLIST ;

#endif // DX_NOTUSE_DRAWFUNCTION






// ストリ??デ??制御用関数?イン??造体?イプ２
typedef struct tagSTREAMDATASHREDTYPE2
{
	int						(*Open)( const TCHAR *Path, int UseCacheFlag, int BlockReadFlag, int UseASyncReadFlag ) ;
	int						(*Close)( int Handle ) ;
	long					(*Tell)( int Handle ) ;
	int						(*Seek)( int Handle, long SeekPoint, int SeekType ) ;
	size_t					(*Read)( void *Buffer, size_t BlockSize, size_t DataNum, int Handle ) ;
	int						(*Eof)( int Handle ) ;
	int						(*IdleCheck)( int Handle ) ;
	int						(*ChDir)( const TCHAR *Path ) ;
	int						(*GetDir)( TCHAR *Buffer ) ;
	int						(*FindFirst)( const TCHAR *FilePath, FILEINFO *Buffer ) ;	// 戻り値: -1=エラ?  -1以外=FindHandle
	int						(*FindNext)( int FindHandle, FILEINFO *Buffer ) ;			// 戻り値: -1=エラ?  0=成功
	int						(*FindClose)( int FindHandle ) ;							// 戻り値: -1=エラ?  0=成功
} STREAMDATASHREDTYPE2 ;

// ストリ??デ??制御用関数?イン??造体
typedef struct tagSTREAMDATASHRED
{
	long					(*Tell)( void *StreamDataPoint ) ;
	int						(*Seek)( void *StreamDataPoint, long SeekPoint, int SeekType ) ;
	size_t					(*Read)( void *Buffer, size_t BlockSize, size_t DataNum, void *StreamDataPoint ) ;
//	size_t					(*Write)( void *Buffer, size_t BlockSize, size_t DataNum, void *StreamDataPoint ) ;
	int						(*Eof)( void *StreamDataPoint ) ;
	int						(*IdleCheck)( void *StreamDataPoint ) ;
	int						(*Close)( void *StreamDataPoint ) ;
} STREAMDATASHRED, *LPSTREAMDATASHRED ;

// ストリ??デ??制御用デ???造体
typedef struct tagSTREAMDATA
{
	STREAMDATASHRED			ReadShred ;
	void					*DataPoint ;
} STREAMDATA ;




#ifndef DX_NOTUSE_DRAWFUNCTION

// メモリに置かれたデ??をフ?イルとして扱うためのデ???造体
typedef struct tagMEMSTREAMDATA
{
	unsigned char			*DataBuffer ;
	unsigned int			DataSize ;
	int						DataPoint ;
	int						EOFFlag ;
} MEMSTREAMDATA, *LPMEMSTREAMDATA ;

// パレット情報?造体
typedef struct tagCOLORPALETTEDATA
{
	unsigned char			Blue ;
	unsigned char			Green ;
	unsigned char			Red ;
	unsigned char			Alpha ;
} COLORPALETTEDATA ;

// カラ??造情報?造体
typedef struct tagCOLORDATA
{
	unsigned short			ColorBitDepth ;									// ビット?度( この値が０の場合は Format が有効になる )
	unsigned short			PixelByte ;										// １ピクセルあたりのバイト数
	unsigned char			RedWidth, GreenWidth, BlueWidth, AlphaWidth ;	// 各色のビット幅
	unsigned char			RedLoc	, GreenLoc  , BlueLoc  , AlphaLoc   ;	// 各色の配置されているビットアドレス
	unsigned int			RedMask , GreenMask , BlueMask , AlphaMask  ;	// 各色のビット?スク
	unsigned int			NoneMask ;										// 使われていないビットの?スク
	COLORPALETTEDATA		Palette[256] ;									// パレット(ビット?度が８以下の場合のみ有効)
	unsigned char			NoneLoc, NoneWidth;								// 使われていないビットのアドレスと幅
	int						Format ;										// フォ??ット( DX_BASEIMAGE_FORMAT_NORMAL 等 )
} COLORDATA, *LPCOLORDATA ;

// 基?イメ?ジデ???造体
typedef struct tagBASEIMAGE
{
	COLORDATA				ColorData ;							// 色情報
	int						Width, Height, Pitch ;				// 幅、高さ、ピッ?
	void					*GraphData ;						// グラフィックイメ?ジ
	int						MipMapCount ;						// ?ップ?ップの数
} BASEIMAGE, GRAPHIMAGE, *LPGRAPHIMAGE ;

// ラインデ???
typedef struct tagLINEDATA
{
	int						x1, y1, x2, y2 ;					// 座標
	int						color ;								// 色
	int						pal ;								// パラメ??
} LINEDATA, *LPLINEDATA ;

// 座標デ???
typedef struct tagPOINTDATA
{
	int						x, y ;								// 座標
	int						color ;								// 色
	int						pal ;								// パラメ??
} POINTDATA, *LPPOINTDATA ;

// イメ?ジフォ??ットデ??
typedef struct tagIMAGEFORMATDESC
{
	unsigned char			TextureFlag ;					// テクス?ャか、フラグ( TRUE:テクス?ャ  FALSE:標?サ?フェス )
	unsigned char			AlphaChFlag ;					// α?ャンネルはあるか、フラグ	( TRUE:ある  FALSE:ない )
	unsigned char			DrawValidFlag ;					// ?画可?か、フラグ( TRUE:可?  FALSE:不可? )
	unsigned char			SystemMemFlag ;					// システ?メモリ上に存在しているか、フラグ( TRUE:システ?メモリ上  FALSE:ＶＲ?Ｍ上 )( 標?サ?フェスの時のみ有効 )
	unsigned char			NotManagedTextureFlag ;			// ?ネ?ジドテクス?ャを使用しないか、フラグ

	unsigned char			BaseFormat ;					// 基?フォ??ット( DX_BASEIMAGE_FORMAT_NORMAL 等 )
	unsigned char			MipMapCount ;					// ?ップ?ップの数
	unsigned char			AlphaTestFlag ;					// αテスト?ャンネルはあるか、フラグ( TRUE:ある  FALSE:ない )( テクス?ャの場合のみ有効 )
	unsigned char			ColorBitDepth ;					// 色?度( テクス?ャの場合のみ有効 )
	unsigned char			BlendGraphFlag ;				// ブレンド用画像か、フラグ
	unsigned char			UsePaletteFlag ;				// パレットを使用しているか、フラグ( SystemMemFlag が TRUE の場合のみ有効 )
} IMAGEFORMATDESC ;

#endif // DX_NOTUSE_DRAWFUNCTION

// DirectInput のジョイパッド入力情報
typedef struct tagDINPUT_JOYSTATE
{
	int						X ;								// スティック0のＸ軸パラメ??( -1000?1000 )
	int						Y ;								// スティック0のＹ軸パラメ??( -1000?1000 )
	int						Z ;								// スティック0のＺ軸パラメ??( -1000?1000 )
	int						Rx ;							// スティック1のＸ軸パラメ??( -1000?1000 )
	int						Ry ;							// スティック1のＹ軸パラメ??( -1000?1000 )
	int						Rz ;							// スティック1のＺ軸パラメ??( -1000?1000 )
	int						Slider[ 2 ] ;					// スライ??二つ
	unsigned int			POV[ 4 ] ;						// ハットスイッ?４つ( -1:入力なし 0:上 4500:右上 9000:右 13500:右下 18000:下 22500:左下 27000:左 31500:左上 )
	unsigned char			Buttons[ 32 ] ;					// ??ン３２個( 押された??ンは 128 になる )
} DINPUT_JOYSTATE ;







// WinSockets使用時のアドレス指定用?造体
typedef struct tagIPDATA
{
	union
	{
		struct
		{
			unsigned char	d1, d2, d3, d4 ;				// アドレス値
		} ;
		unsigned int		dall ;
	} ;
} IPDATA, *LPIPDATA ;

#define DX_STRUCT_END

}

// 関数プロト?イプ宣言------------------------------------------------------------------

namespace DxLib
{

#define DX_FUNCTION_START

// DxWin.cpp関数プロト?イプ宣言

// 初期化終了系関数
extern	int			DxLib_Init( void ) ;													// ライブラリ初期化関数
extern	int			DxLib_End( void ) ;														// ライブラリ使用の終了関数

extern	int			DxLib_GlobalStructInitialize( void ) ;									// ライブラリの内部で使用している?造体を?ロ初期化して、DxLib_Init の前に行った設定を無効化する( DxLib_Init の前でのみ有効 )
extern	int			DxLib_IsInit( void ) ;													// ライブラリが初期化されているかどうかを取得する( 戻り値: TRUE=初期化されている  FALSE=されていない )

// エラ?処理関数
extern	int			ErrorLogAdd( const TCHAR *ErrorStr ) ;									// エラ?文書を書き出す
extern 	int			ErrorLogFmtAdd( const TCHAR *FormatString , ... ) ;						// 書式付きエラ?文書を書き出す
extern	int			ErrorLogTabAdd( void ) ;												// ?ブ数を増やす
extern	int			ErrorLogTabSub( void ) ;												// ?ブ数を減らす
extern	int			SetUseTimeStampFlag( int UseFlag ) ;									// ?イ?ス?ンプの有無を設定する
extern 	int			AppLogAdd( const TCHAR *String , ... ) ;								// 書式付きログ文字列を書き出す

// メモリ確保系関数
extern	void*		DxAlloc( size_t AllocSize , const char *File = NULL , int Line = -1 ) ;	// メモリを確保する
extern	void*		DxCalloc( size_t AllocSize , const char *File = NULL , int Line = -1 ) ;	// メモリを確保して０で初期化する
extern	void*		DxRealloc( void *Memory , size_t AllocSize , const char *File = NULL , int Line = -1 ) ;	// メモリの再確保を行う
extern	void		DxFree( void *Memory ) ;												// メモリを解放する
extern	size_t		DxSetAllocSizeTrap( size_t Size ) ;										// 列挙対象にするメモリの確保容量をセットする
extern	int			DxSetAllocPrintFlag( int Flag ) ;										// ＤＸライブラリ内でメモリ確保が行われる時に情報を出力するかどうかをセットする
extern	size_t		DxGetAllocSize( void ) ;												// DxAlloc や DxCalloc で確保しているメモリサイズを取得する
extern	int			DxGetAllocNum( void ) ;													// DxAlloc や DxCalloc で確保しているメモリの数を取得する
extern	void		DxDumpAlloc( void ) ;													// DxAlloc や DxCalloc で確保しているメモリを列挙する
extern	int			DxErrorCheckAlloc( void ) ;												// 確保したメモリ情報が破壊されていないか調べる( -1:破壊あり  0:なし )
extern	int			DxSetAllocSizeOutFlag( int Flag ) ;										// メモリが確保、解放が行われる度に確保しているメモリの容量を出力するかどうかのフラグをセットする
extern	int			DxSetAllocMemoryErrorCheckFlag( int Flag ) ;							// メモリの確保、解放が行われる度に確保しているメモリ確保情報が破損していないか調べるかどうかのフラグをセットする

// ログ出力??関数
extern	int			SetLogDrawOutFlag( int DrawFlag ) ;										// ログ出力フラグをセットする
extern 	int			GetLogDrawFlag( void ) ;												// ログ出力をするかフラグの取得

// 簡易画面出力関数
extern 	int			printfDx( const TCHAR *FormatString , ... ) ;							// 簡易画面出力
extern	int			clsDx( void ) ;															// 簡易画面出力をクリアする

// フ?イルアクセス関数
extern	int			FileRead_open( const TCHAR *FilePath , int ASync = FALSE ) ;			// フ?イルを開く
extern	int			FileRead_size( const TCHAR *FilePath ) ;								// フ?イルのサイズを得る
extern	int			FileRead_close( int FileHandle ) ;									// フ?イルを閉じる
extern	int			FileRead_tell( int FileHandle ) ;									// フ?イル?イン?の現在位置を得る
extern	int			FileRead_seek( int FileHandle , int Offset , int Origin ) ;			// フ?イル?イン?の位置を変更する
extern	int			FileRead_read( void *Buffer , int ReadSize , int FileHandle ) ;		// フ?イルからデ??を読み込む
extern	int			FileRead_idle_chk( int FileHandle ) ;								// フ?イル読み込みが完了しているかどうかを取得する
extern	int			FileRead_eof( int FileHandle ) ;									// フ?イルの終?かどうかを得る
extern	int			FileRead_gets( TCHAR *Buffer , int BufferSize , int FileHandle ) ;	// フ?イルから文字列を読み出す
extern	TCHAR		FileRead_getc( int FileHandle ) ;									// フ?イルから一文字読み出す
extern	int			FileRead_scanf( int FileHandle , const TCHAR *Format , ... ) ;		// フ?イルから書式化されたデ??を読み出す

extern	int			FileRead_createInfo( const TCHAR *ObjectPath ) ;						// フ?イル情報ハンドルを作成する( 戻り値  -1:エラ?  -1以外:フ?イル情報ハンドル )
extern	int			FileRead_getInfoNum( int FileInfoHandle ) ;							// フ?イル情報ハンドル中のフ?イルの数を取得する
extern	int			FileRead_getInfo( int Index , FILEINFO *Buffer , int FileInfoHandle ) ;	// フ?イル情報ハンドル中のフ?イルの情報を取得する
extern	int			FileRead_deleteInfo( int FileInfoHandle ) ;							// フ?イル情報ハンドルを削除する

extern	int			FileRead_findFirst( const TCHAR *FilePath, FILEINFO *Buffer ) ;		// 指定のフ?イル又はフォル?の情報を取得し、フ?イル検索ハンドルも作成する( 戻り値: -1=エラ?  -1以外=フ?イル検索ハンドル )
extern	int			FileRead_findNext( int FindHandle, FILEINFO *Buffer ) ;				// 条件の合致する次のフ?イルの情報を取得する( 戻り値: -1=エラ?  0=成功 )
extern	int			FileRead_findClose( int FindHandle ) ;								// フ?イル検索ハンドルを閉じる( 戻り値: -1=エラ?  0=成功 )

// 便利関数
extern	int			GetResourceInfo( const TCHAR *ResourceName , const TCHAR *ResourceType , void **DataPointerP , int *DataSizeP ) ;		// 指定のリ??スを取得する( -1:失敗  0:成功 )
extern	TCHAR*		GetResourceIDString( int ResourceID ) ;																				// リ??スＩＤからリ??スＩＤ文字列を得る 

// メッセ?ジ処理関数
extern	int			ProcessMessage( void ) ;												// ウインドウズのメッセ?ジル?プに代わる処理を行う

// ウインドウ関係情報取得関数
extern	int			GetWindowCRect( RECT *RectBuf ) ;										// ウインドウのクライアント領域を取得する
extern	int			GetWindowActiveFlag( void ) ;											// ウインドウのアクティブフラグを取得
extern	HWND		GetMainWindowHandle( void ) ;											// メインウインドウのハンドルを取得する
extern	int			GetWindowModeFlag( void ) ;												// ウインドウモ?ドで起動しているか、のフラグを取得する
extern	int			GetDefaultState( int *SizeX , int *SizeY , int *ColorBitDepth ) ;		// 起動時のデスクトップの画面モ?ドを取得する
extern	int			GetActiveFlag( void ) ;													// ?フトがアクティブかどうかを取得する
extern	int			GetNoActiveState( int ResetFlag = TRUE ) ;								// 非アクティブになり、処理が一時停?していたかどうかを取得する(引数 ResetFlag=TRUE:状態をリセット FALSE:状態をリセットしない    戻り値: 0=一時停?はしていない  1=一時停?していた )
extern	int			GetMouseDispFlag( void ) ;												// ?ウスを?示するかどうかのフラグを取得する
extern	int			GetAlwaysRunFlag( void ) ;												// ウインドウがアクティブではない状態でも処理を続行するか、フラグを取得する
extern	int			_GetSystemInfo( int *DxLibVer , int *DirectXVer , int *WindowsVer ) ;	// ＤＸライブラリと DirectX のバ?ジョンと Windows のバ?ジョンを得る
extern	int			GetPcInfo( TCHAR *OSString , TCHAR *DirectXString ,
								TCHAR *CPUString , int *CPUSpeed /* 単位MHz */ ,
								double *FreeMemorySize /* 単位MByte */ , double *TotalMemorySize ,
								TCHAR *VideoDriverFileName , TCHAR *VideoDriverString ,
								double *FreeVideoMemorySize /* 単位MByte */ , double *TotalVideoMemorySize ) ;	// ＰＣの情報を得る
extern	int			GetUseMMXFlag( void ) ;													// ＭＭＸが使えるかどうかの情報を得る
extern	int			GetUseSSEFlag( void ) ;													// ＳＳＥが使えるかどうかの情報を得る
extern	int			GetUseSSE2Flag( void ) ;												// ＳＳＥ２が使えるかどうかの情報を得る
extern	int			GetWindowCloseFlag( void ) ;											// ウインドウを閉じようとしているかの情報を得る
extern	HINSTANCE	GetTaskInstance( void ) ;												// ?フトのインス?ンスを取得する
extern	int			GetUseWindowRgnFlag( void ) ;											// リ?ジョンを使っているかどうかを取得する
extern	int			GetWindowSizeChangeEnableFlag( int *FitScreen = NULL ) ;				// ウインドウのサイズを変更できるかどうかのフラグを取得する
extern	double		GetWindowSizeExtendRate( double *ExRateX = NULL , double *ExRateY = NULL ) ;	// ?画画面のサイズに対するウインドウサイズの比率を取得する( 戻り値は ExRateX に代入される値と同じです )
extern	int			GetWindowSize( int *Width, int *Height ) ;								// ウインドウモ?ドのウインドウののクライアント領域のサイズを取得する
extern	int			GetWindowPosition( int *x, int *y ) ;									// ウインドウモ?ドのウインドウの位置を取得する( 枠も含めた左上座標 )
extern	int			GetWindowUserCloseFlag( int StateResetFlag = FALSE ) ;					// ウインドウの閉じる??ンが押されたかどうかを取得する
extern	int			GetNotDrawFlag( void ) ;												// ?画??を使うかどうかのフラグを取得する
extern	int			GetPaintMessageFlag( void ) ;											// WM_PAINT メッセ?ジが来たかどうかを取得する(戻り値  TRUE:WM_PAINTメッセ?ジが来た(一度取得すると以後、再び WM_PAINTメッセ?ジが来るまで FALSE が返ってくるようになる)  FALSE:WM_PAINT メッセ?ジは来ていない)
extern	int			GetValidHiPerformanceCounter( void ) ;									// パフォ??ンスカウン?が有効かどうかを取得する(戻り値  TRUE:有効  FALSE:無効)

// 設定系関数
extern	int			ChangeWindowMode( int Flag ) ;											// ウインドウモ?ドを変更する
extern	int			SetUseCharSet( int CharSet /* = DX_CHARSET_SHFTJIS 等 */ ) ;			// ＤＸライブラリの文字列処理で前提とする文字列セットを設定する
extern	int			LoadPauseGraph( const TCHAR *FileName ) ;								// アクティブウインドウが他の?フトに移っている際に?示する画像のロ?ド(NULL で解除)
extern	int			LoadPauseGraphFromMem( void *MemImage , int MemImageSize ) ;			// アクティブウインドウが他の?フトに移っている際に?示する画像のロ?ド(NULL で解除)
extern	int			SetActiveStateChangeCallBackFunction( int (* CallBackFunction )( int ActiveState , void *UserData ) , void *UserData ) ;	// ウインドウのアクティブ状態に変化があったときに呼ばれるコ?ルバック関数をセットする( NULL をセットすると呼ばれなくなる )
extern	int			SetWindowText( const TCHAR *WindowText ) ;								// メインウインドウのウインドウテキストを変更する
extern	int			SetMainWindowText( const TCHAR *WindowText ) ;							// メインウインドウのウインドウテキストを変更する
extern	int			SetMainWindowClassName( const TCHAR *ClassName ) ;						// メインウインドウのクラス名を設定する
extern	int			SetOutApplicationLogValidFlag( int Flag ) ;								// ログ出力を行うか否かのセット
extern	int			SetApplicationLogSaveDirectory( const TCHAR *DirectoryPath ) ;			// ログフ?イルを保存するディレクトリパスを設定する
extern	int			SetAlwaysRunFlag( int Flag ) ;											// ウインドウがアクティブではない状態でも処理を続行するか、フラグをセットする
extern	int			SetWindowIconID( int ID ) ;												// 使用するアイコンのＩＤをセットする
extern	int			SetUseASyncChangeWindowModeFunction( int Flag ,
										 void (* CallBackFunction )( void * ) , void *Data ) ;	// 最大化??ンやALT+ENTERキ?による非同期なウインドウモ?ドの変更の??の設定を行う
extern	int			SetWindowStyleMode( int Mode ) ;										// ウインドウのス?イルを変更する
extern	int			SetWindowSizeChangeEnableFlag( int Flag, int FitScreen = TRUE ) ;		// ウインドウのサイズを変更できるかどうかのフラグをセットする( NotFitScreen:ウインドウのクライアント領域に画面をフィットさせる(拡大させる)かどうか  TRUE:フィットさせる  FALSE:フィットさせない )
extern	int			SetWindowSizeExtendRate( double ExRateX, double ExRateY = -1.0 ) ;		// ?画画面のサイズに対するウインドウサイズの比率を設定する( ExRateY が?イナスの場合は ExRateX の値が ExRateY にも使用されます )
extern	int			SetWindowSize( int Width, int Height ) ;								// ウインドウモ?ド時のウインドウのクライアント領域のサイズを設定する
extern	int			SetWindowPosition( int x, int y ) ;										// ウインドウモ?ドのウインドウの位置を設定する( 枠も含めた左上座標 )
extern	int			SetSysCommandOffFlag( int Flag , const TCHAR *HookDllPath = NULL ) ;	// ?スクスイッ?を有効にするかどうかを設定する
extern	int			SetHookWinProc( WNDPROC WinProc ) ;										// メッセ?ジをフックするウインドウプロ?ジャを登?する
extern	int			SetDoubleStartValidFlag( int Flag ) ;									// ２重起動を許すかどうかのフラグをセットする
extern	int			AddMessageTakeOverWindow( HWND Window ) ;								// メッセ?ジ処理をＤＸライブラリに肩代わりしてもらうウインドウを追加する
extern	int			SubMessageTakeOverWindow( HWND Window ) ;								// メッセ?ジ処理をＤＸライブラリに肩代わりしてもらうウインドウを減らす

extern	int			SetWindowInitPosition( int x , int y ) ;									// ウインドウの初期位置を設定する
extern	int			SetNotWinFlag( int Flag ) ;												// ＤＸライブラリのウインドウ関連の??を使用しないフラグ
extern	int			SetNotDrawFlag( int Flag ) ;											// ?画??を使うかどうかのフラグをセットする
extern	int			SetNotSoundFlag( int Flag ) ;											// サウンド??を使うかどうかのフラグをセットする
extern	int			SetNotInputFlag( int Flag ) ;											// 入力状態の取得??を使うかどうかのフラグをセットする
extern	int			SetDialogBoxHandle( HWND WindowHandle ) ;								// ＤＸライブラリでメッセ?ジ処理を行う?イアログ?ックスを登?する
extern	int			ChangeStreamFunction( STREAMDATASHREDTYPE2 *StreamThread ) ;			// ＤＸライブラリでストリ??デ??アクセスに使用する関数を変更する
extern	int			GetStreamFunctionDefault( void ) ;										// ＤＸライブラリでストリ??デ??アクセスに使用する関数がデフォルトのものか調べる( TRUE:デフォルト  FALSE:デフォルトではない )
extern	int			SetWindowVisibleFlag( int Flag ) ;										// メインウインドウを?示するかどうかのフラグをセットする
extern	int			SetWindowUserCloseEnableFlag( int Flag ) ;								// メインウインドウの???ンを押した時にライブラリが自動的にウインドウを閉じるかどうかのフラグをセットする
extern	int			SetDxLibEndPostQuitMessageFlag( int Flag ) ;							// ＤＸライブラリ終了時に PostQuitMessage を呼ぶかどうかのフラグをセットする
extern	int			SetUserWindow( HWND WindowHandle ) ;									// ＤＸライブラリで利用するウインドウのハンドルをセットする(DxLib_Init を実行する以前でのみ有効)
extern	int			SetUserWindowMessageProcessDXLibFlag( int Flag ) ;						// SetUseWindow で設定したウインドウのメッセ?ジル?プ処理をＤＸライブラリで行うかどうか、フラグをセットする
extern	int			SetUseDXArchiveFlag( int Flag ) ;										// ＤＸア?カイブフ?イルの読み込み??を使うかどうかを設定する( FALSE:使用しない  TRUE:使用する )
extern	int			SetDXArchivePriority( int Priority = 0 ) ;								// ＤＸア?カイブフ?イルと通常のフォル?のどちらも存在した場合、どちらを優先させるかを設定する( 1:フォル?を優先 0:ＤＸア?カイブフ?イルを優先(デフォルト) )
extern	int			SetDXArchiveExtension( const TCHAR *Extension = NULL ) ;				// 検索するＤＸア?カイブフ?イルの拡張子を変更する
extern	int			SetDXArchiveKeyString( const TCHAR *KeyString = NULL ) ;				// ＤＸア?カイブフ?イルの鍵文字列を設定する
extern	int			SetUseDateNameLogFile( int Flag ) ;										// ログフ?イル名に日付をつけるかどうかをセットする
extern	int			SetBackgroundColor( int Red, int Green, int Blue ) ;					// メインウインドウのバックグラウンドカラ?を設定する
extern	int			SetLogFontSize( int Size ) ;											// printfDx で画面に出力するログフォントのサイズを変更する
extern	int			SetUseFPUPreserveFlag( int Flag ) ;										// FPUの精度を落とさない設定を使用するかどうかを設定する、DxLib_Init を呼び出す前のみ有効( TRUE:使用する(精度が落ちない)  FALSE:使用しない(精度を落とす(デフォルト) )
extern	int			SetValidMousePointerWindowOutClientAreaMoveFlag( int Flag ) ;			// ?ウス?イン?がウインドウのクライアントエリアの外にいけるかどうかを設定する( TRUE:いける( デフォルト設定 )  FALSE:いけない )
extern	int			SetUseBackBufferTransColorFlag( int Flag ) ;							// バックバッフ?の透過色の部分を透過させるかどうかを設定する( TRUE:透過させる  FALSE:透過させない )
extern	int			SetResourceModule( HMODULE ResourceModule ) ;							// リ??スを読み込む際に使用するモジュ?ルを設定する( NULL を指定すると初期状態に戻ります、デフォルトでは NULL )

// クリップ??ド関係
extern	int			GetClipboardText( TCHAR *DestBuffer ) ;									// クリップ??ドに格?されているテキストデ??を読み出す、-1 の場合はクリップ??ドにテキストデ??は無いということ( DestBuffer に NULL を渡すと格?に必要なデ??サイズが返ってくる )
extern	int			SetClipboardText( const TCHAR *Text ) ;									// クリップ??ドにテキストデ??を格?する

// ドラッグ＆ドロップされたフ?イル関係
extern	int			SetDragFileValidFlag( int Flag ) ;										// フ?イルのドラッグ＆ドロップ??を有効にするかどうかのフラグをセットする
extern	int			DragFileInfoClear( void ) ;												// ドラッグ＆ドロップされたフ?イルの情報を初期化する
extern	int			GetDragFilePath( TCHAR *FilePathBuffer ) ;								// ドラッグ＆ドロップされたフ?イル名を取得する( -1:取得できなかった  0:取得できた )
extern	int			GetDragFileNum( void ) ;												// ドラッグ＆ドロップされたフ?イルの数を取得する

// ウインドウ?画領域設定系関数
extern	HRGN		CreateRgnFromGraph( int Width , int Height , void *MaskData , int Pitch , int Byte ) ; // 任意のグラフィックからRGNハンドルを作成する
extern	HRGN		CreateRgnFromBaseImage( BASEIMAGE *BaseImage, int TransColorR, int TransColorG, int TransColorB ) ;		// 任意の基?イメ?ジデ??と透過色からRGNハンドルを作成する
extern	int			SetWindowRgnGraph( const TCHAR *FileName ) ;							// 任意のグラフィックからＲＧＮをセットする
extern	int			UpdateTransColorWindowRgn( void ) ;										// ?画先の画面の透過色の部分を透過させるＲＧＮをセットする

// ツ?ルバ?関係
extern	int			SetupToolBar( const TCHAR *BitmapName , int DivNum , int ResourceID = -1 ) ;				// ツ?ルバ?の?備( NULL を指定するとツ?ルバ?を解除、ResourceID は BitmapName が NULL の際に使用される )
extern	int			AddToolBarButton( int Type /* TOOLBUTTON_TYPE_NORMAL 等 */ , int State /* TOOLBUTTON_STATE_ENABLE 等 */ , int ImageIndex, int ID ) ;		// ツ?ルバ?に??ンを追加
extern	int			AddToolBarSep( void ) ;												// ツ?ルバ?に隙間を追加
extern	int			GetToolBarButtonState( int ID ) ;									// ツ?ルバ?の??ンの状態を取得( TRUE:押されている or 押された  FALSE:押されていない )
extern	int			SetToolBarButtonState( int ID , int State ) ;						// ツ?ルバ?の??ンの状態を設定
extern	int			DeleteAllToolBarButton( void ) ;									// ツ?ルバ?の??ンを全て削除

// メニュ?関係
extern	int			SetUseMenuFlag( int Flag ) ;												// メニュ?を有効にするかどうかを設定する
extern	int			SetUseKeyAccelFlag( int Flag ) ;											// キ???ドアクセラレ???を使用するかどうかを設定する

extern	int			AddKeyAccel( const TCHAR *ItemName , int ItemID , int KeyCode , int CtrlFlag , int AltFlag , int ShiftFlag ) ;	// ショ?トカットキ?を追加する
extern	int			AddKeyAccel_Name( const TCHAR *ItemName , int KeyCode , int CtrlFlag , int AltFlag , int ShiftFlag ) ;	// ショ?トカットキ?を追加する
extern	int			AddKeyAccel_ID( int ItemID, int KeyCode, int CtrlFlag, int AltFlag, int ShiftFlag ) ;	// ショ?トカットキ?を追加する
extern	int			ClearKeyAccel( void ) ;														// ショ?トカットキ?の情報を初期化する

extern	int			AddMenuItem( int AddType /* MENUITEM_ADD_CHILD等 */ , const TCHAR *ItemName, int ItemID,
									int SeparatorFlag, const TCHAR *NewItemName = NULL , int NewItemID = -1 ) ;	// メニュ?に?目を追加する
extern	int			DeleteMenuItem( const TCHAR *ItemName, int ItemID ) ;						// メニュ?から選択?目を削除する
extern	int			CheckMenuItemSelect( const TCHAR *ItemName, int ItemID ) ;					// メニュ?が選択されたかどうかを取得する( 0:選択されていない  1:選択された )
extern	int			SetMenuItemEnable( const TCHAR *ItemName, int ItemID, int EnableFlag ) ;		// メニュ?の?目を選択出来るかどうかを設定する
extern	int			SetMenuItemMark( const TCHAR *ItemName, int ItemID, int Mark ) ;				// メニュ?の?目に?ェック??クやラジオ??ンを?示するかどうかを設定する( MENUITEM_MARK_NONE 等 )
extern	int			CheckMenuItemSelectAll( void ) ;											// メニュ?の?目がどれか選択されたかどうかを取得する( 戻り値  TRUE:どれか選択された  FALSE:選択されていない )

extern	int			AddMenuItem_Name( const TCHAR *ParentItemName, const TCHAR *NewItemName ) ;	// メニュ?に選択?目を追加する
extern	int			AddMenuLine_Name( const TCHAR *ParentItemName ) ;							// メニュ?のリストに区切り線を追加する
extern	int			InsertMenuItem_Name( const TCHAR *ItemName, const TCHAR *NewItemName ) ;		// 指定の?目と、指定の?目の一つ上の?目との間に新しい?目を追加する
extern	int			InsertMenuLine_Name( const TCHAR *ItemName ) ;								// 指定の?目と、指定の?目の一つ上の?目との間に区切り線を追加する
extern	int			DeleteMenuItem_Name( const TCHAR *ItemName ) ;								// メニュ?から選択?目を削除する
extern	int			CheckMenuItemSelect_Name( const TCHAR *ItemName ) ;							// メニュ?が選択されたかどうかを取得する( 0:選択されていない  1:選択された )
extern	int			SetMenuItemEnable_Name( const TCHAR *ItemName, int EnableFlag ) ;			// メニュ?の?目を選択出来るかどうかを設定する( 1:選択できる  0:選択できない )
extern	int			SetMenuItemMark_Name( const TCHAR *ItemName, int Mark ) ;					// メニュ?の?目に?ェック??クやラジオ??ンを?示するかどうかを設定する( MENUITEM_MARK_NONE 等 )

extern	int			AddMenuItem_ID( int ParentItemID, const TCHAR *NewItemName, int NewItemID = -1 ) ;	// メニュ?に選択?目を追加する
extern	int			AddMenuLine_ID( int ParentItemID ) ;										// メニュ?のリストに区切り線を追加する
extern	int			InsertMenuItem_ID( int ItemID, int NewItemID ) ;							// 指定の?目と、指定の?目の一つ上の?目との間に新しい?目を追加する
extern	int			InsertMenuLine_ID( int ItemID, int NewItemID ) ;							// 指定の?目と、指定の?目の一つ上の?目との間に区切り線を追加する
extern	int			DeleteMenuItem_ID( int ItemID ) ;											// メニュ?から選択?目を削除する
extern	int			CheckMenuItemSelect_ID( int ItemID ) ;										// メニュ?が選択されたかどうかを取得する( 0:選択されていない  1:選択された )
extern	int			SetMenuItemEnable_ID( int ItemID, int EnableFlag ) ;						// メニュ?の?目を選択出来るかどうかを設定する
extern	int			SetMenuItemMark_ID( int ItemID, int Mark ) ;								// メニュ?の?目に?ェック??クやラジオ??ンを?示するかどうかを設定する( MENUITEM_MARK_NONE 等 )

extern	int			DeleteMenuItemAll( void ) ;													// メニュ?の全ての選択?目を削除する
extern	int			ClearMenuItemSelect( void ) ;												// メニュ?が選択されたかどうかの情報を初期化
extern	int			GetMenuItemID( const TCHAR *ItemName ) ;										// メニュ?の?目名からＩＤを取得する
extern	int			GetMenuItemName( int ItemID, TCHAR *NameBuffer ) ;							// メニュ?の?目名からＩＤを取得する
extern	int 		LoadMenuResource( int MenuResourceID ) ;									// メニュ?をリ??スから読み込む
extern	int			SetMenuItemSelectCallBackFunction( void (* CallBackFunction )( const TCHAR *ItemName, int ItemID ) ) ; // メニュ?の選択?目が選択されたときに呼ばれるコ?ルバック関数を設定する

extern	int			SetWindowMenu( int MenuID, int (* MenuProc )( WORD ID ) ) ;				// (古い関数)ウインドウにメニュ?を設定する
extern	int			SetDisplayMenuFlag( int Flag ) ;										// メニュ?を?示するかどうかをセットする
extern	int			GetDisplayMenuFlag( void ) ;											// メニュ?を?示しているかどうかを取得する
extern	int			GetUseMenuFlag( void ) ;												// メニュ?を使用しているかどうかを得る
extern	int			SetAutoMenuDisplayFlag( int Flag ) ;									// フルスクリ?ン時にメニュ?を自動で?示したり非?示にしたりするかどうかのフラグをセットする

// ?ウス関係関数
extern	int			SetMouseDispFlag( int DispFlag ) ;										// ?ウスの?示フラグのセット
extern	int			GetMousePoint( int *XBuf, int *YBuf ) ;									// ?ウスの位置を取得する
extern	int			SetMousePoint( int PointX, int PointY ) ;								// ?ウスの位置をセットする
extern	int			GetMouseInput( void ) ;													// ?ウスの??ンの状態を得る 
extern	int			GetMouseWheelRotVol( int CounterReset = TRUE ) ;						// ?ウスホイ?ルの回?量を得る
extern	int			GetMouseInputLog( int *Button, int *ClickX, int *ClickY, int LogDelete = TRUE ) ;	// ?ウスのクリック情報を取得する( 戻り値  -1:ログが無かった )

// ウエイト系関数
extern	int			WaitTimer( int WaitTime ) ;												// 指定の時間だけ処理をとめる
extern	int			WaitKey( void ) ;														// キ?の入力待ち

// カウン?及び時刻取得系関数
extern	int			GetNowCount( int UseRDTSCFlag = FALSE ) ;								// ?リ秒単位の精度を持つカウン?の現在値を得る
extern	LONGLONG	GetNowHiPerformanceCount( int UseRDTSCFlag = FALSE ) ;					// GetNowCountの高精度バ?ジョン
extern	int			GetDateTime( DATEDATA *DateBuf ) ;										// 現在時刻を取得する 

// 乱数取得
extern	int			GetRand( int RandMax ) ;												// 乱数を取得する( RandMax : 返って来る値の最大値 )
extern	int			SRand( int Seed ) ;														// 乱数の初期値を設定する

#ifndef DX_NON_NETWORK

// 通信関係
extern	int			ProcessNetMessage( int RunReleaseProcess = FALSE ) ;					// 通信メッセ?ジの処理をする関数

extern	int			GetHostIPbyName( const TCHAR *HostName, IPDATA *IPDataBuf ) ;			// ＤＮＳサ?バ?を使ってホスト名からＩＰアドレスを取得する
extern 	int			ConnectNetWork( IPDATA IPData, int Port = -1 ) ;						// 他?シンに接続する
extern 	int			PreparationListenNetWork( int Port = -1 ) ;								// 接続を受けられる状態にする
extern 	int			StopListenNetWork( void ) ;												// 接続を受けつけ状態の解除
extern 	int			CloseNetWork( int NetHandle ) ;											// 接続を終了する

extern 	int			GetNetWorkAcceptState( int NetHandle ) ;								// 接続状態を取得する
extern 	int			GetNetWorkDataLength( int NetHandle ) ;									// 受信デ??の量を得る
extern	int			GetNetWorkSendDataLength( int NetHandle ) ;								// 未送信のデ??の量を得る 
extern 	int			GetNewAcceptNetWork( void ) ;											// 新たに接続した通信回線を得る
extern 	int			GetLostNetWork( void ) ;												// 接続を切断された通信回線を得る
extern 	int			GetNetWorkIP( int NetHandle, IPDATA *IpBuf ) ;							// 接続先のＩＰを得る
extern	int			GetMyIPAddress( IPDATA *IpBuf ) ;										// 自分のＩＰを得る
extern	int			SetConnectTimeOutWait( int Time ) ;										// 接続の?イ?アウトまでの時間を設定する
extern	int			SetUseDXNetWorkProtocol( int Flag ) ;									// ＤＸライブラリの通信?態を使うかどうかをセットする
extern	int			GetUseDXNetWorkProtocol( void ) ; 										// ＤＸライブラリの通信?態を使うかどうかを取得する
extern	int			SetUseDXProtocol( int Flag ) ;											// SetUseDXNetWorkProtocol の別名
extern	int			GetUseDXProtocol( void ) ; 												// GetUseDXNetWorkProtocol の別名
extern	int			SetNetWorkCloseAfterLostFlag( int Flag ) ;								// 接続が切断された直後に接続ハンドルを解放するかどうかのフラグをセットする
extern	int			GetNetWorkCloseAfterLostFlag( void ) ;									// 接続が切断された直後に接続ハンドルを解放するかどうかのフラグを取得する
//extern	int			SetProxySetting( int UseFlag, const char *Address, int Port ) ;						// ＨＴＴＰ通信で使用するプロキシ設定を行う
//extern	int			GetProxySetting( int *UseFlagBuffer, char *AddressBuffer, int *PortBuffer ) ;	// ＨＴＴＰ通信で使用するプロキシ設定を取得する
//extern	int			SetIEProxySetting( void ) ;												// ＩＥのプロキシ設定を適応する

extern 	int			NetWorkRecv( int NetHandle, void *Buffer, int Length ) ;				// 受信したデ??を読み込む
extern	int			NetWorkRecvToPeek( int NetHandle, void *Buffer, int Length ) ;			// 受信したデ??を読み込む、読み込んだデ??はバッフ?から削除されない
extern	int			NetWorkRecvBufferClear( int NetHandle ) ;								// 受信したデ??をクリアする
extern 	int			NetWorkSend( int NetHandle, void *Buffer, int Length ) ;				// デ??を送信する

extern	int			MakeUDPSocket( int RecvPort = -1 ) ;																	// UDPを使用した通信を行う?ケットハンドルを作成する( RecvPort を -1 にすると送信専用の?ケットハンドルになります )
extern	int			DeleteUDPSocket( int NetUDPHandle ) ;																	// UDPを使用した通信を行う?ケットハンドルを削除する
extern	int			NetWorkSendUDP( int NetUDPHandle, IPDATA SendIP, int SendPort, void *Buffer, int Length ) ;				// UDPを使用した通信で指定のＩＰにデ??を送信する、Length は最大65507、SendPort を -1 にすると MakeUDPSocket に RecvPort で渡した??トが使用されます( 戻り値  0以上;送信できたデ??サイズ  -1:エラ?  -2:送信デ??が大きすぎる  -3:送信?備ができていない  )
extern	int			NetWorkRecvUDP( int NetUDPHandle, IPDATA *RecvIP, int *RecvPort, void *Buffer, int Length, int Peek ) ;	// UDPを使用した通信でデ??を受信する、Peek に TRUE を渡すと受信に成功してもデ??を受信キュ?から削除しません( 戻り値  0以上:受信したデ??のサイズ  -1:エラ?  -2:バッフ?のサイズが足りない  -3:受信デ??がない )
//extern int		CheckNetWorkSendUDP( int NetUDPHandle ) ;																// UDPを使用した通信でデ??が送信できる状態かどうかを調べる( 戻り値  -1:エラ?  TRUE:送信可?  FALSE:送信不可? )
extern	int			CheckNetWorkRecvUDP( int NetUDPHandle ) ;																// UDPを使用した通信で新たな受信デ??が存在するかどうかを調べる( 戻り値  -1:エラ?  TRUE:受信デ??あり  FALSE:受信デ??なし )

/*	使用不可
extern	int			HTTP_FileDownload( const char *FileURL, const char *SavePath = NULL ,
										 void **SaveBufferP = NULL , int *FileSize = NULL ,
										 char **ParamList = NULL ) ;						// HTTP を使用してネットワ?ク上のフ?イルを?ウンロ?ドする
extern	int			HTTP_GetFileSize( const char *FileURL ) ;								// HTTP を使用してネットワ?ク上のフ?イルのサイズを得る

extern	int			HTTP_StartFileDownload( const char *FileURL, const char *SavePath, void **SaveBufferP = NULL , char **ParamList = NULL ) ;	// HTTP を使用したネットワ?ク上のフ?イルを?ウンロ?ドする処理を開始する
extern	int			HTTP_StartGetFileSize( const char *FileURL ) ;							// HTTP を使用したネットワ?ク上のフ?イルのサイズを得る処理を開始する
extern	int			HTTP_Close( int HttpHandle ) ;											// HTTP の処理を終了し、ハンドルを解放する
extern	int			HTTP_CloseAll( void ) ;													// 全てのハンドルに対して HTTP_Close を行う
extern	int			HTTP_GetState( int HttpHandle ) ;										// HTTP 処理の現在の状態を得る( NET_RES_COMPLETE 等 )
extern	int			HTTP_GetError( int HttpHandle ) ;										// HTTP 処理でエラ?が発生した場合、エラ?の内容を得る( HTTP_ERR_NONE 等 )
extern	int			HTTP_GetDownloadFileSize( int HttpHandle ) ;							// HTTP 処理で対象となっているフ?イルのサイズを得る( 戻り値: -1 = エラ?・若しくはまだフ?イルのサイズを取得していない  0以上 = フ?イルのサイズ )
extern	int			HTTP_GetDownloadedFileSize( int HttpHandle ) ;							// HTTP 処理で既に?ウンロ?ドしたフ?イルのサイズを取得する

extern	int			fgetsForNetHandle( int NetHandle, char *strbuffer ) ;					// fgets のネットワ?クハンドル版( -1:取得できず 0:取得できた )
extern	int			URLAnalys( const char *URL, char *HostBuf = NULL , char *PathBuf = NULL ,
												 char *FileNameBuf = NULL , int *PortBuf = NULL ) ;	// ＵＲＬを解析する
extern	int			URLConvert( char *URL, int ParamConvert = TRUE , int NonConvert = FALSE ) ;	// HTTP に渡せない記号が使われた文字列を渡せるような文字列に変換する( 戻り値: -1 = エラ?  0以上 = 変換後の文字列のサイズ )
extern	int			URLParamAnalysis( char **ParamList, char **ParamStringP ) ;				// HTTP 用パラメ??リストから一つのパラメ??文字列を作成する( 戻り値:  -1 = エラ?  0以上 = パラメ??の文字列の長さ )
*/

#endif


// 文字コ?ドバッフ??作関係
extern	int			StockInputChar( TCHAR CharCode ) ;																												// バッフ?にコ?ドをストックする
extern	int			ClearInputCharBuf( void ) ;																														// 文字コ?ドバッフ?をクリアする
extern	TCHAR		GetInputChar( int DeleteFlag ) ;																												// 文字コ?ドバッフ?に溜まったデ??から文字コ?ドを取得する
extern	TCHAR		GetInputCharWait( int DeleteFlag ) ;																											// 文字コ?ドバッフ?に溜まったデ??から１バイト分取得する、バッフ?になにも文字コ?ドがない場合はキ?が押されるまで待つ

extern	int			GetOneChar( TCHAR *CharBuffer, int DeleteFlag ) ;																								// 文字コ?ドバッフ?に溜まったデ??から１文字分取得する
extern	int			GetOneCharWait( TCHAR *CharBuffer, int DeleteFlag ) ;																							// 文字コ?ドバッフ?に溜まったデ??から１文字分取得する、バッフ?に何も文字コ?ドがない場合はキ?が押されるまで待つ
extern	int			GetCtrlCodeCmp( TCHAR Char ) ;																													// アスキ?コントロ?ルコ?ドか調べる

#ifndef DX_NON_KEYEX

extern	int			DrawIMEInputString( int x, int y, int SelectStringNum ) ;																						// 画面上に入力中の文字列を?画する
extern	int			SetUseIMEFlag( int UseFlag ) ;																													// ＩＭＥを使用するかどうかをセットする
extern	int			SetInputStringMaxLengthIMESync( int Flag ) ;																									// ＩＭＥで入力できる最大文字数を MakeKeyInput の設定に合わせるかどうかをセットする( TRUE:あわせる  FALSE:あわせない(デフォルト) )
extern	int			SetIMEInputStringMaxLength( int Length ) ;																										// ＩＭＥで一度に入力できる最大文字数を設定する( 0:制限なし  1以上:指定の文字数で制限 )

#endif

extern	int			GetStringPoint( const TCHAR *String, int Point ) ;																								// 全角文字、半角文字入り乱れる中から指定の文字数での半角文字数を得る
extern	int			GetStringPoint2( const TCHAR *String, int Point ) ;																								// 全角文字、半角文字入り乱れる中から指定の文字数での全角文字数を得る

extern	int			DrawObtainsString( int x, int y, int AddY, const TCHAR *String, int StrColor, int StrEdgeColor = 0 , int FontHandle = -1 , int SelectBackColor = -1 , int SelectStrColor = 0 , int SelectStrEdgeColor = -1 , int SelectStart = -1 , int SelectEnd = -1 ) ;					// 規定領域に収めたかたちで文字列を?画
extern	int			DrawObtainsBox( int x1, int y1, int x2, int y2, int AddY, int Color, int FillFlag ) ;															// 規定領域に収めたかたちで矩?を?画 

#ifndef DX_NON_KEYEX

extern	int			InputStringToCustom( int x, int y, int BufLength, TCHAR *StrBuffer, int CancelValidFlag, int SingleCharOnlyFlag, int NumCharOnlyFlag ) ;			// 文字列の入力取得

extern	int			KeyInputString( int x, int y, int CharMaxLength, TCHAR *StrBuffer, int CancelValidFlag ) ;														// 文字列の入力取得
extern	int			KeyInputSingleCharString( int x, int y, int CharMaxLength, TCHAR *StrBuffer, int CancelValidFlag ) ;												// 半角文字列のみの入力取得
extern	int			KeyInputNumber( int x, int y, int MaxNum, int MinNum, int CancelValidFlag ) ;																	// 数値の入力

extern	int			GetIMEInputModeStr( TCHAR *GetBuffer ) ;																											// IMEの入力モ?ド文字列の取得
extern	IMEINPUTDATA* GetIMEInputData( void ) ;																														// IMEで入力中の文字列の情報を取得する
#ifdef DX_GCC_COMPILE
extern	int			SetKeyInputStringColor( ULONGLONG NmlStr, ULONGLONG NmlCur, ULONGLONG IMEStr, ULONGLONG IMECur, ULONGLONG IMELine, ULONGLONG IMESelectStr, ULONGLONG IMEModeStr , ULONGLONG NmlStrE = 0 , ULONGLONG IMESelectStrE = 0 , ULONGLONG IMEModeStrE = 0 , ULONGLONG IMESelectWinE = 0xffffffffffffffffULL ,	ULONGLONG IMESelectWinF = 0xffffffffffffffffULL , ULONGLONG SelectStrBackColor = 0xffffffffffffffffULL , ULONGLONG SelectStrColor = 0xffffffffffffffffULL , ULONGLONG SelectStrEdgeColor = 0xffffffffffffffffULL ) ;	// InputString関数使用時の文字の各色を変更する
#else
extern	int			SetKeyInputStringColor( ULONGLONG NmlStr, ULONGLONG NmlCur, ULONGLONG IMEStr, ULONGLONG IMECur, ULONGLONG IMELine, ULONGLONG IMESelectStr, ULONGLONG IMEModeStr , ULONGLONG NmlStrE = 0 , ULONGLONG IMESelectStrE = 0 , ULONGLONG IMEModeStrE = 0 , ULONGLONG IMESelectWinE = 0xffffffffffffffff ,	ULONGLONG IMESelectWinF = 0xffffffffffffffff , ULONGLONG SelectStrBackColor = 0xffffffffffffffff , ULONGLONG SelectStrColor = 0xffffffffffffffff , ULONGLONG SelectStrEdgeColor = 0xffffffffffffffff ) ;	// InputString関数使用時の文字の各色を変更する
#endif
extern	int			SetKeyInputStringFont( int FontHandle ) ;																										// キ?入力文字列?画関連で使用するフォントのハンドルを変更する(-1でデフォルトのフォントハンドル)
extern	int			DrawKeyInputModeString( int x, int y ) ;																										// 入力モ?ド文字列を?画する

extern	int			InitKeyInput( void ) ;																															// キ?入力デ??初期化
extern	int			MakeKeyInput( int MaxStrLength, int CancelValidFlag, int SingleCharOnlyFlag, int NumCharOnlyFlag ) ;											// 新しいキ?入力デ??の作成
extern	int			DeleteKeyInput( int InputHandle ) ;																												// キ?入力デ??の削除
extern	int			SetActiveKeyInput( int InputHandle ) ;																											// 指定のキ?入力をアクティブにする( -1 を指定するとアクティブなキ?入力ハンドルが無い状態になります )
extern	int			GetActiveKeyInput( void ) ;																														// 現在アクティブになっているキ?入力ハンドルを取得する
extern	int			CheckKeyInput( int InputHandle ) ;																												// 入力が終了しているか取得する
extern	int			ReStartKeyInput( int InputHandle ) ;																											// 入力が完了したキ?入力を再度編集状態に戻す
extern	int			ProcessActKeyInput( void ) ;																													// キ?入力処理関数
extern	int			DrawKeyInputString( int x, int y, int InputHandle ) ;																							// キ?入力中デ??の?画

extern	int			SetKeyInputSelectArea( int SelectStart, int SelectEnd, int InputHandle ) ;																		// キ?入力デ??の指定の領域を選択状態にする( SelectStart と SelectEnd に -1 を指定すると選択状態が解除されます )
extern	int			GetKeyInputSelectArea( int *SelectStart, int *SelectEnd, int InputHandle ) ;																	// キ?入力デ??の選択領域を取得する
extern	int			SetKeyInputDrawStartPos( int DrawStartPos, int InputHandle ) ;																					// キ?入力の?画開始文字位置を設定する
extern	int			GetKeyInputDrawStartPos( int InputHandle ) ;																									// キ?入力の?画開始文字位置を取得する
extern	int			SetKeyInputCursorBrinkTime( int Time ) ;																										// キ?入力時のカ??ルの?滅する早さをセットする
extern	int			SetKeyInputCursorBrinkFlag( int Flag ) ;																										// キ?入力時のカ??ルを?滅させるかどうかをセットする
extern	int			SetKeyInputString( const TCHAR *String, int InputHandle ) ;																						// キ?入力デ??に指定の文字列をセットする
extern	int			SetKeyInputNumber( int Number, int InputHandle ) ;																								// キ?入力デ??に指定の数値を文字に置き換えてセットする
extern	int			SetKeyInputNumberToFloat( float Number, int InputHandle ) ;																						// キ?入力デ??に指定の浮動小数?値を文字に置き換えてセットする
extern	int			GetKeyInputString( TCHAR *StrBuffer, int InputHandle ) ;																							// 入力デ??の文字列を取得する
extern	int			GetKeyInputNumber( int InputHandle ) ;																											// 入力デ??の文字列を整数値として取得する
extern	float		GetKeyInputNumberToFloat( int InputHandle ) ;																									// 入力デ??の文字列を浮動小数?値として取得する
extern	int			SetKeyInputCursorPosition( int Position, int InputHandle ) ;																									// キ?入力の現在のカ??ル位置を設定する
extern	int			GetKeyInputCursorPosition( int InputHandle ) ;																									// キ?入力の現在のカ??ル位置を取得する

#endif


// メモリに置かれたデ??をフ?イルのデ??に例えてつかうための関数
extern	void*		MemStreamOpen( void *DataBuffer, unsigned int DataSize ) ;
extern	int			MemStreamClose( void *StreamDataPoint ) ;












// DxInput.cpp関数プロト?イプ宣言

// 入力状態取得関数
extern	int			CheckHitKey( int KeyCode ) ;											// キ???ドの入力状態取得
extern	int			CheckHitKeyAll( int CheckType = DX_CHECKINPUT_ALL ) ;					// 全キ?の押下状態を取得
extern	int			GetHitKeyStateAll( DX_CHAR *KeyStateBuf ) ;								// すべてのキ?の押下状態を取得する
extern	int			SetKeyExclusiveCooperativeLevelFlag( int Flag ) ;						// キ???ドの協調レベルを排他レベルにするかどうかのフラグをセットする
extern	int			GetJoypadNum( void ) ;													// ジョイパッドが接続されている数を取得する
extern	int			GetJoypadInputState( int InputType ) ;									// ジョイバッドの入力状態取得
extern	int			GetJoypadAnalogInput( int *XBuf, int *YBuf, int InputType ) ;			// ジョイパッドのアナログ的なスティック入力情報を得る
extern	int			GetJoypadAnalogInputRight( int *XBuf, int *YBuf, int InputType ) ;		// ジョイパッドのアナログ的なスティック入力情報を得る(右スティック用)
extern	int			GetJoypadDirectInputState( int InputType, DINPUT_JOYSTATE *DInputState ) ;	// DirectInput から得られるジョイパッドの生のデ??を取得する( DX_CHECKINPUT_KEY や DX_INPUT_KEY_PAD1 を引数に渡すとエラ? )
extern	int			KeyboradBufferProcess( void ) ;											// キ???ドのバッフ?からデ??を取得する処理
extern	int			GetJoypadGUID( int PadIndex, GUID *GuidBuffer ) ;						// ジョイパッドのＧＵIＤを得る
extern	int			ConvertKeyCodeToVirtualKey( int KeyCode ) ;								// ＤＸライブラリのキ?コ?ドから Windows の仮想キ?コ?ドを取得する
extern	int			SetJoypadInputToKeyInput( int InputType, int PadInput, int KeyInput1, int KeyInput2 = -1 , int KeyInput3 = -1 , int KeyInput4 = -1  ) ; // ジョイパッドの入力に対応したキ???ドの入力を設定する
extern	int			SetJoypadDeadZone( int InputType, double Zone ) ;						// ジョイパッドの無効??ンの設定を行う
extern	int			StartJoypadVibration( int InputType, int Power, int Time ) ;			// ジョイパッドの振動を開始する
extern	int			StopJoypadVibration( int InputType ) ;									// ジョイパッドの振動を停?する
extern	int			GetJoypadPOVState( int InputType, int POVNumber ) ;						// ジョイパッドのＰＯＶ入力の状態を得る( 単位は角度の１００?  中心位置にある場合は -1 が返る )
extern	int			GetJoypadName( int InputType, TCHAR *InstanceNameBuffer, TCHAR *ProductNameBuffer ) ;	// ジョイパッドのデバイス登?名と製品登?名を取得する
extern	int			ReSetupJoypad( void ) ;													// ジョイパッドの再セットアップを行う( 新たに接続されたジョイパッドがある場合に検出される )

extern	int			SetKeyboardNotDirectInputFlag( int Flag ) ;								// キ???ドの入力処理に DirectInput を使わないか、フラグをセットする
extern	int			SetUseDirectInputFlag( int Flag ) ;										// 入力処理に DirectInput を使用するかどうかのフラグをセットする
extern	int			SetUseJoypadVibrationFlag( int Flag ) ;									// ジョイパッドの振動??を使用するかどうかのフラグをセットする








#ifndef DX_NOTUSE_DRAWFUNCTION

// DxDraw.cpp関数プロト?イプ宣言

// 設定関係関数
extern	int			Set2D3DKyouzonFlag( int Flag ) ;							// ３Ｄと２Ｄの共存率を上げるフラグのセット
extern	int			SetNotUse3DFlag( int Flag ) ;								// ３Ｄ??を使わないフラグのセット
extern	int			SetBasicBlendFlag( int Flag ) ;								// 簡略化ブレンド処理を行うか否かのフラグをセットする
extern	int			SetScreenMemToVramFlag( int Flag ) ;						// 画面デ??をＶＲ?Ｍに置くか、フラグ
extern	int			SetUseSoftwareRenderModeFlag( int Flag ) ;					// ?フトウエアレン?リングモ?ドを使用するかどうかをセットする
extern	int			SetUseDirectDrawFlag( int Flag ) ;							// ＤｉｒｅｃｔＤｒａｗを使用するかどうかをセットする
extern	int			SetUseGDIFlag( int Flag ) ;									// ＧＤＩ?画を必要とするか、を変更する
extern	int			SetDDrawUseGuid( GUID *Guid ) ;								// ＤｉｒｅｃｔＤｒａｗが使用するＧＵＤＩを設定する
extern	int			SetDisplayRefreshRate( int RefreshRate ) ;					// フルスクリ?ン時の画面のリフレッシュレ?トを変更する(Windows2000以?のみ有効)
extern	int			SetMultiThreadFlag( int Flag ) ;							// DirectDraw や Direct3D の協調レベルを?ル?スレッド対応にするかどうかをセットする
extern	int			SetUseDirectDrawDeviceIndex( int Index ) ;					// 使用する DirectDraw デバイスのインデックスを設定する
extern	int			SetUseTempFrontScreen( int Flag ) ;							// 一時退避用?画面を使用するかどうかを設定する( TRUE:使用する  FALSE:使用しない )

// ＤｉｒｅｃｔＤｒａｗ関係情報提供関数
extern	int						GetDrawScreenSize( int *XBuf, int *YBuf ) ;							// ?画サイズを取得する
extern	int						GetScreenBitDepth( void ) ;											// 使用色ビット数を返す
extern	int						GetBmpSurf3DRenderingValidState( int BmpIndex ) ;					// 指定のインデックスのビット?ップデ??が３Ｄデバイスによる?画が可?かどうかを取得する( TRUE:出来る  FALSE:出来ない )
extern	void*					GetDrawTargetSurface( void ) ;	/* 戻り値を IDirectDrawSurface7 * にキャストして下さい */		// ?画対象となっているサ?フェスを取得
extern	void*					GetPrimarySurface( void ) ;		/* 戻り値を IDirectDrawSurface7 * にキャストして下さい */		// プライ?リサ?フェスを取得
extern	void*					GetBackSurface( void ) ;		/* 戻り値を IDirectDrawSurface7 * にキャストして下さい */		// バックサ?フェスを取得
extern	void*					GetWorkSurface( void ) ;		/* 戻り値を IDirectDrawSurface7 * にキャストして下さい */		// 作業用サ?フェスを取得
extern	int						GetDesktopDrawCmp( void ) ;											// デスクトップ画面への?画かの判定情報
extern	void*					GetUseDDrawObj( void ) ;		/* 戻り値を IDirectDraw7 * にキャストして下さい */			// 現在使用しているＤｉｒｅｃｔＤｒａｗオブジェクトのアドレスを取得する
extern  int						GetUseDirectDrawFlag( void ) ;										// ＤｉｒｅｃｔＤｒａｗを使用するかどうかを取得する
extern	int						GetColorBitDepth( void ) ;											// 画面の色ビット?度を得る
extern	int						GetChangeDisplayFlag( void ) ;										// 画面モ?ドが変更されているかどうかのフラグを取得する
extern	COLORDATA*				GetDispColorData( void ) ;											// ディスプレ?のカラ?デ???イン?を得る
extern	const D_DDPIXELFORMAT*	GetPixelFormat( void ) ;											// ピクセルフォ??ットの取得
extern	int						GetScreenMemToSystemMemFlag( void ) ;								// 画面グラフィックデ??がシステ?メモリに存在するかフラグの取得
extern	const D_DDPIXELFORMAT*	GetOverlayPixelFormat( void ) ;										// 使用できるオ?バ?レイのピクセルフォ??ットを得る
extern	D_DDCAPS				GetDirectDrawCaps( void ) ;											// DirectDraw の情報を得る
extern	int						GetVideoMemorySize( int *AllSize, int *FreeSize ) ;					// ビデオメモリの容量を得る
extern	int						GetUseGDIFlag( void ) ;												// ＧＤＩ?画を必要とするかどうかを取得する
extern	int						GetNotDraw3DFlag( void ) ;											// NotDraw3DFlag を取得する
extern	HDC						GetDrawScreenDC( void ) ;											// ?画先になっている画面のＤＣを取得する
extern	int						ReleaseDrawScreenDC( HDC Dc ) ;										// GetScreenDC で取得したＤＣを解放する
extern	GUID*					GetDirectDrawDeviceGUID( int Number ) ;								// 有効な DirectDraw デバイスの GUID を取得する
extern	int						GetDirectDrawDeviceDescription( int Number, char *StringBuffer ) ;	// 有効な DirectDraw デバイスの名前を得る
extern	int						GetDirectDrawDeviceNum( void ) ;									// 有効な DirectDraw デバイスの数を取得する
extern	int						GetUseMEMIMGFlag( void ) ;											// MEMIMG ?造体を使用するかどうかを取得する
extern	int						GetVSyncTime( void ) ;												// 垂直同期信号一回に付きかかる時間を?リ秒単位で取得する
extern	int						GetRefreshRate( void ) ;											// 現在の画面のリフレッシュレ?トを取得する
extern	int						GetDisplayModeNum( void ) ;											// 変更可?なディスプレイモ?ドの数を取得する
extern	DISPLAYMODEDATA			GetDisplayMode( int ModeIndex ) ;									// 変更可?なディスプレイモ?ドの情報を取得する( ModeIndex は 0 ? GetDisplayModeNum の戻り値-1 )

// パレット?作関係関数
extern 	int			SetPalette( int PalIndex, int Red, int Green, int Blue ) ;							// パレットのセット
extern 	int			ReflectionPalette( void ) ;															// セットしたパレットをハ?ドウエアに反映させる
extern 	int			GetPalette( int PalIndex, int *Red, int *Green, int *Blue ) ;						// パレットの取得
extern	int			SetBmpPal( const TCHAR *FileName ) ;													// ＢＭＰフ?イルのパレットを反映させる
extern	int			SetBmpPalPart( const TCHAR *FileName, int StartNum, int GetNum, int SetNum ) ;		// ＢＭＰフ?イルからのパレットの部分取得
extern	int			GetGraphPalette( int GrHandle, int ColorIndex, int *Red, int *Green, int *Blue ) ;	// メモリ上に読み込んだ画像のパレットを取得する(フルカラ?画像の場合は無効)
extern  int			GetGraphOriginalPalette( int GrHandle, int ColorIndex, int *Red, int *Green, int *Blue ) ; // メモリ上に読み込んだ画像の SetGraphPalette で変更する前のパレットを取得する
extern	int			SetGraphPalette( int GrHandle, int ColorIndex, int Color ) ;							// メモリ上に読み込んだ画像のパレットを変更する(フルカラ?画像の場合は無効)
extern	int			ResetGraphPalette( int GrHandle ) ;													// SetGraphPalette で変更したパレットを全て元に戻す

// 簡易グラフィック関係関数
extern	int			GetPixel( int x, int y ) ;																											// 指定座標の色を取得する
extern	int			Paint( int x, int y, int FillColor, int BoundaryColor = -1 ) ;																		// 指定?から境界色があるところまで塗りつぶす(境界色を -1 にすると指定?の色の領域を塗りつぶす)
extern	int			BltFastOrBitBlt( D_IDirectDrawSurface7 *Dest, D_IDirectDrawSurface7 *Src, int DestX, int DestY, RECT *SrcRect, int BltType = -1 ) ;	// 指定のサ?フェスから指定のサ?フェスへグラフィックデ??を?送する

// ウエイト関係関数
extern	int			WaitVSync( int SyncNum ) ;																												// 垂直同期信号を待つ

// 画面?作関係関数
extern	int			ScreenFlip( void ) ;																													// 裏画面と?画面を交換する
extern 	int			ScreenCopy( void ) ;																													// 裏画面の内容を?画面に?画する
extern	int			BltBackScreenToWindow( HWND Window, int ClientX, int ClientY ) ;																		// 裏画面の内容を指定のウインドウに?送する
extern	int			BltRectBackScreenToWindow( HWND Window, RECT BackScreenRect, RECT WindowClientRect ) ;													// 裏画面の指定の領域をウインドウのクライアント領域の指定の領域に?送する
extern	int			GraphCopy( RECT *SrcRect, RECT *DestRect, int SrcHandle, int DestHandle = DX_SCREEN_BACK ) ;											// 画像の内容をコピ?する
extern	int			SetGraphMode( int ScreenSizeX, int ScreenSizeY, int ColorBitDepth, int RefreshRate = 60 ) ;												// 画面モ?ドを設定する
extern	int			SetGraphDisplayArea( int x1, int y1, int x2, int y2 ) ;																					// ScreenFlip 時に?画面全体に?送する裏画面の領域を設定する( DxLib_Init の前でのみ使用可? )
extern	int			SetChangeScreenModeGraphicsSystemResetFlag( int Flag ) ;																				// 画面モ?ド変更時( とウインドウモ?ド変更時 )にグラフィックスシステ?の設定やグラフィックハンドルをリセットするかどうかを設定する( TRUE:リセットする  FALSE:リセットしない )


// ＢＭＰ保存関数
// Jpeg_Quality         = 0:低画質?100:高画質
// Png_CompressionLevel = 0:無圧縮?  9:最高圧縮
extern	int			SaveDrawScreen( int x1, int y1, int x2, int y2, const TCHAR *FileName, int SaveType = DX_IMAGESAVETYPE_BMP , int Jpeg_Quality = 80 , int Jpeg_Sample2x1 = TRUE , int Png_CompressionLevel = -1 ) ;		// 現在?画対象になっている画面を保存する
extern	int			SaveDrawScreenToBMP( int x1, int y1, int x2, int y2, const TCHAR *FileName ) ;														// 現在?画対象になっている画面をＢＭＰ?式で保存する
extern	int			SaveDrawScreenToJPEG( int x1, int y1, int x2, int y2, const TCHAR *FileName, int Quality = 80 , int Sample2x1 = TRUE ) ;				// 現在?画対象になっている画面をＪＰＥＧ?式で保存する Quality = 画質、値が大きいほど低圧縮高画質,0?100 
extern	int			SaveDrawScreenToPNG( int x1, int y1, int x2, int y2, const TCHAR *FileName, int CompressionLevel = -1 ) ;							// 現在?画対象になっている画面をＰＮＧ?式で保存する CompressionLevel = 圧縮率、値が大きいほど高圧縮率高負荷、０は無圧縮,0?9









// Dx3D.cpp関数プロト?イプ宣言

// 設定関係
extern	D_IDirect3DDevice7* GetUseD3DDevObj( void ) ;																// 使用中のＤｉｒｅｃｔ３ＤＤｅｖｉｃｅオブジェクトを得る
extern	int			SetUseDivGraphFlag( int Flag ) ;																// 必要ならグラフィックの分割を行うか、フラグのセット
extern	int			SetUseMaxTextureSize( int Size ) ;																// 使用するテクス?ャ?の最大サイズをセット(0でデフォルト)
extern	int			SetUseVertexBufferFlag( int Flag ) ;															// 頂?バッフ?を使用するかどうかを設定する
//extern int		RenderVertexBuffer( void ) ;																	// 頂?バッフ?に溜まった頂?デ??を吐き出す
//extern VERTEX_2D*	GetVertexBuffer( int VertexNum = 6 , int PrimType = DX_PRIMTYPE_TRIANGLELIST ) ;				// 追加頂?バッフ?の頂?追加アドレスを得る( 戻り値はテクス?ャなしの場合は VERTEX_NOTEX_2D となる )
//extern void		_DrawPreparation( int GrHandle = DX_NONE_GRAPH , int ParamFlag = 0 ) ;							// ?画?備を行う( ParamFlag は DRAWPREP_TRANS 等 )
//extern void		Add4VertexBuffer( void ) ;																		// GetVertexTo3DDevice によって４頂?追加されたことを前提に頂?追加処理を行う
//extern void		AddVertexBuffer( int VertexNum = 6 ) ;															// GetVertexTo3DDevice によって指定数頂?が追加されたことを前提に頂?追加処理を行う
//extern void		SetGraphTexture( int GrHandle ) ;																// Ｄｉｒｅｃｔ３Ｄデバイスにテクス?ャをセットする
extern	int			SetUseOldDrawModiGraphCodeFlag( int Flag ) ;													// 以前の DrawModiGraph 関数のコ?ドを使用するかどうかのフラグをセットする

// その他補助関数
extern D_DDPIXELFORMAT*	GetTexPixelFormat( int AlphaCh, int AlphaTest, int ColorBitDepth, int DrawValid = FALSE ) ;	// ピクセルフォ??ットを得る
extern COLORDATA*		GetTexColorData( int AlphaCh, int AlphaTest, int ColorBitDepth, int DrawValid = FALSE ) ;	// カラ?デ??を得る
extern D_DDPIXELFORMAT*	GetTexPixelFormat( IMAGEFORMATDESC *Format ) ;												// フォ??ットに基づいたカラ?フォ??ットを得る
extern COLORDATA*		GetTexColorData( IMAGEFORMATDESC *Format ) ;												// フォ??ットに基づいたカラ?デ??を得る
extern D_DDPIXELFORMAT*	GetTexPixelFormat( int FormatIndex ) ;														// 指定のフォ??ットインデックスのカラ?フォ??ットを得る
extern COLORDATA*		GetTexColorData( int FormatIndex ) ;														// 指定のフォ??ットインデックスのカラ?デ??を得る
extern D_DDPIXELFORMAT*	GetZBufferPixelFormat( int BitDepth ) ;														// 指定のビット?度のＺバッフ??のピクセルフォ??ットを得る( 現在のところ 16 ビットのみ )








// DxGraphics関数プロト?イプ宣言

// グラフィック制御関係関数
extern	int			MakeGraph( int SizeX, int SizeY, int NotUse3DFlag = FALSE ) ;																								// 空のグラフィックを作成
extern	int			MakeScreen( int SizeX, int SizeY ) ;																														// ?画可?な画面を作成
extern	int			DeleteGraph( int GrHandle, int LogOutFlag = FALSE ) ;																										// 指定のグラフィックハンドルを削除する
extern	int			DeleteSharingGraph( int GrHandle ) ;																														// 指定のグラフィックハンドルと、同じグラフィックデ??から派生しているグラフィックハンドル( DerivationGraph で派生したハンドル、LoadDivGraph 読み込んで作成された複数のハンドル )を一度に削除する
extern	int			GetGraphNum( void ) ;																																		// 有効なグラフィックの数を取得する
extern	int			SetGraphLostFlag( int GrHandle, int *LostFlag ) ;																											// 解放時に立てるフラグの?イン?をセットする
extern	int			InitGraph( int LogOutFlag = FALSE ) ;																														// 画像デ??の初期化

extern	int			BltBmpToGraph( COLORDATA *SrcColor, HBITMAP Bmp, HBITMAP AlphaMask, const TCHAR *GraphName, int CopyPointX, int CopyPointY, int GrHandle, int ReverseFlag ) ; // 画像デ??の?送
extern	int			BltBmpToDivGraph( COLORDATA *SrcColor, HBITMAP Bmp, HBITMAP AlphaMask, const TCHAR *GraphName, int AllNum, int XNum, int YNum, int Width, int Height, int *GrHandle, int ReverseFlag ) ;	// 分割画像へのＢＭＰの?送
extern	int			BltBmpOrGraphImageToGraph( COLORDATA *SrcColorData, HBITMAP Bmp, HBITMAP AlphaMask, const TCHAR *GraphName,
										int BmpFlag, BASEIMAGE *RgbImage, BASEIMAGE *AlphaImage,
										int CopyPointX, int CopyPointY, int GrHandle, int ReverseFlag ) ;																		// ＢＭＰ か GraphImage を画像に?送
extern	int			BltBmpOrGraphImageToGraph2( COLORDATA *SrcColorData, HBITMAP Bmp, HBITMAP AlphaMask, const TCHAR *GraphName,
										int BmpFlag, BASEIMAGE *RgbImage, BASEIMAGE *AlphaImage,
										RECT *SrcRect, int DestX, int DestY, int GrHandle, int ReverseFlag ) ;																	// ＢＭＰ か GraphImage を画像に?送
extern	int			BltBmpOrGraphImageToDivGraph( COLORDATA *SrcColor, HBITMAP Bmp, HBITMAP AlphaMask, const TCHAR *GraphName,
										int BmpFlag, BASEIMAGE *RgbImage, BASEIMAGE *AlphaImage,
										int AllNum, int XNum, int YNum, int Width, int Height, int *GrHandle, int ReverseFlag ) ;												// 分割画像への ＢＭＰ か GraphImage の?送

#ifndef DX_NON_MOVIE
extern	int			OpenMovieToOverlay( const TCHAR *FileName ) ;																												// オ?バ?レイサ?フェスを使用した??ビ?フ?イルのオ?プン
extern	int			UpdateMovieToOverlay( int x, int y, int ExRate, int ShowFlag, int MovieHandle ) ;																			// オ?バ?レイサ?フェスを使用した??ビ?の?示ステ??スセット
extern	int			CloseMovieToOverlay( int MovieHandle ) ;																													// オ?バ?レイサ?フェスを使用した??ビ?フ?イルを閉じる
#endif
extern	int			ReloadFileGraphAll( void ) ;																																// フ?イルから読み込んだ画像情報を再度読み込む
extern	int			SetGraphTransColor( int GrHandle, int Red, int Green, int Blue ) ;																							// 画像の透過色を変更する(アルフ??ャンネル使用時は無効)

extern	int			RestoreGraph( int GrHandle ) ;																																// 画像デ??のリストア
extern	int			AllRestoreGraph( void ) ;																																	// すべての画像デ??のリストア


// グラフィック?画関係関数
extern	int			ClearDrawScreen( RECT *ClearRect = NULL ) ;																											// 画面の状態を初期化する
extern	int			ClearDrawScreenZBuffer( RECT *ClearRect = NULL ) ;																									// 画面のＺバッフ?の状態を初期化する
extern	int			ClsDrawScreen( void ) ;																																// 画面の状態を初期化する(ClearDrawScreenの旧名称)

extern	int			LoadGraphScreen( int x, int y, const TCHAR *GraphName, int TransFlag ) ;																				// ＢＭＰフ?イルを読みこんで画面に?画する
extern	int			DrawGraph( int x, int y, int GrHandle, int TransFlag ) ;																							// グラフィックの?画
extern	int			DrawGraphF( float xf, float yf, int GrHandle, int TransFlag ) ;																						// グラフィックの?画
extern	int			DrawExtendGraph( int x1, int y1, int x2, int y2, int GrHandle, int TransFlag ) ;																	// グラフィックの拡大縮小?画
extern	int			DrawExtendGraphF( float x1f, float y1f, float x2f, float y2, int GrHandle, int TransFlag ) ;														// グラフィックの拡大縮小?画
extern	int			DrawRotaGraph( int x, int y, double ExRate, double Angle, int GrHandle, int TransFlag, int TurnFlag = FALSE  ) ;									// グラフィックの回??画
extern	int			DrawRotaGraphF( float xf, float yf, double ExRate, double Angle, int GrHandle, int TransFlag, int TurnFlag = FALSE  ) ;								// グラフィックの回??画
extern	int			DrawRotaGraph2( int x, int y, int cx, int cy, double ExtRate, double Angle, int GrHandle, int TransFlag, int TurnFlag = FALSE  ) ;					// グラフィックの回??画２
extern	int			DrawRotaGraph2F( float xf, float yf, float cxf, float cyf, double ExtRate, double Angle, int GrHandle, int TransFlag, int TurnFlag = FALSE  ) ;		// グラフィックの回??画２
extern	int			DrawModiGraph( int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int GrHandle, int TransFlag ) ;										// 画像の自由変??画
extern	int			DrawModiGraphF( float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, int GrHandle, int TransFlag ) ;						// 画像の自由変??画( float 版 )
extern	int			DrawTurnGraph( int x, int y, int GrHandle, int TransFlag ) ;																						// 画像の左右反??画
extern	int			DrawTurnGraphF( float xf, float yf, int GrHandle, int TransFlag ) ;																					// 画像の左右反??画
extern	int			DrawChipMap( int Sx, int Sy, int XNum, int YNum, int *MapData, int ChipTypeNum, int MapDataPitch, int *GrHandle, int TransFlag ) ;					// ?ップグラフィックを使った?ップ?画
extern	int			DrawChipMap( int MapWidth, int MapHeight, int *MapData, int ChipTypeNum, int *ChipGrHandle, int TransFlag,
										int MapDrawPointX, int MapDrawPointY, int MapDrawWidth, int MapDrawHeight, int ScreenX, int ScreenY ) ;							// ?ップグラフィックを使った?ップ?画
extern	int			DrawTile( int x1, int y1, int x2, int y2, int Tx, int Ty,
								double ExtRate, double Angle, int GrHandle, int TransFlag ) ;																			// グラフィックを指定領域に?イル状に?画する
extern	int			DrawRectGraph( int DestX, int DestY, int SrcX, int SrcY, int Width, int Height, int GraphHandle, int TransFlag, int TurnFlag ) ;					// グラフィックの指定矩?部分のみを?画
extern	int			DrawRectExtendGraph( int DestX1, int DestY1, int DestX2, int DestY2, int SrcX, int SrcY, int SrcWidth, int SrcHeight, int GraphHandle, int TransFlag ) ;	// グラフィックの指定矩?部分のみを拡大?画
extern	int			DrawRectRotaGraph( int X, int Y, int SrcX, int SrcY, int Width, int Height, double ExtRate, double Angle, int GraphHandle, int TransFlag, int TurnFlag ) ; 
extern	int			DrawRectGraphF( float DestX, float DestY, int SrcX, int SrcY, int Width, int Height, int GraphHandle, int TransFlag, int TurnFlag ) ;					// グラフィックの指定矩?部分のみを?画
extern	int			DrawRectExtendGraphF( float DestX1, float DestY1, float DestX2, float DestY2, int SrcX, int SrcY, int SrcWidth, int SrcHeight, int GraphHandle, int TransFlag ) ;	// グラフィックの指定矩?部分のみを拡大?画
extern	int			DrawRectRotaGraphF( float X, float Y, int SrcX, int SrcY, int Width, int Height, double ExtRate, double Angle, int GraphHandle, int TransFlag, int TurnFlag ) ; 
extern	int			DrawBlendGraph( int x, int y, int GrHandle, int TransFlag, int BlendGraph, int BorderParam, int BorderRange ) ;										// ブレンド画像と合成して画像を?画する
extern	int			DrawBlendGraphPos( int x, int y, int GrHandle, int TransFlag, int bx, int by, int BlendGraph, int BorderParam, int BorderRange ) ;					// ブレンド画像と合成して画像を?画する( ブレンド画像の起?座標を指定する版 )
extern	int			DrawCircleGauge( int CenterX, int CenterY, double Percent, int GrHandle ) ;																			// ?グラフ的な?画を行う
extern	int			DrawGraphToZBuffer( int X, int Y, int GrHandle, int WriteZMode /* DX_ZWRITE_MASK 等 */ ) ;															// Ｚバッフ?に対して画像の?画を行う
extern	int			DrawTurnGraphToZBuffer( int x, int y, int GrHandle, int WriteZMode /* DX_ZWRITE_MASK 等 */ ) ;														// Ｚバッフ?に対して画像の左右反??画
extern	int			DrawExtendGraphToZBuffer( int x1, int y1, int x2, int y2, int GrHandle, int WriteZMode /* DX_ZWRITE_MASK 等 */ ) ;									// Ｚバッフ?に対して画像の拡大縮小?画
extern	int			DrawRotaGraphToZBuffer( int x, int y, double ExRate, double Angle, int GrHandle, int WriteZMode /* DX_ZWRITE_MASK 等 */ , int TurnFlag = FALSE  ) ;	// Ｚバッフ?に対して画像の回??画
extern	int			DrawModiGraphToZBuffer( int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int GrHandle, int WriteZMode /* DX_ZWRITE_MASK 等 */ ) ;	// Ｚバッフ?に対して画像の自由変??画
extern	int			DrawBoxToZBuffer( int x1, int y1, int x2, int y2, int FillFlag, int WriteZMode /* DX_ZWRITE_MASK 等 */ ) ;											// Ｚバッフ?に対して矩?の?画を行う
extern	int			DrawCircleToZBuffer( int x, int y, int r, int FillFlag, int WriteZMode /* DX_ZWRITE_MASK 等 */ ) ;													// Ｚバッフ?に対して?の?画を行う
extern	int			DrawStringToZBuffer( int x, int y, const TCHAR *String, int WriteZMode /* DX_ZWRITE_MASK 等 */ ) ;															// Ｚバッフ?に対して文字列の?画
extern	int			DrawVStringToZBuffer( int x, int y, const TCHAR *String, int WriteZMode /* DX_ZWRITE_MASK 等 */ ) ;															// Ｚバッフ?に対して文字列の?画
extern	int			DrawStringToHandleToZBuffer( int x, int y, const TCHAR *String, int FontHandle, int WriteZMode /* DX_ZWRITE_MASK 等 */ , int VerticalFlag = FALSE ) ;		// Ｚバッフ?に対して文字列を?画する
extern	int			DrawVStringToHandleToZBuffer( int x, int y, const TCHAR *String, int FontHandle, int WriteZMode /* DX_ZWRITE_MASK 等 */ ) ;									// Ｚバッフ?に対して文字列を?画する
extern	int			DrawFormatStringToZBuffer( int x, int y, int WriteZMode /* DX_ZWRITE_MASK 等 */, const TCHAR *FormatString, ... ) ;																			// Ｚバッフ?に対して書式指定文字列を?画する
extern	int			DrawFormatVStringToZBuffer( int x, int y, int WriteZMode /* DX_ZWRITE_MASK 等 */, const TCHAR *FormatString, ... ) ;																		// Ｚバッフ?に対して書式指定文字列を?画する
extern	int			DrawFormatStringToHandleToZBuffer( int x, int y, int FontHandle, int WriteZMode /* DX_ZWRITE_MASK 等 */, const TCHAR *FormatString, ... ) ;													// Ｚバッフ?に対して書式指定文字列を?画する
extern	int			DrawFormatVStringToHandleToZBuffer( int x, int y, int FontHandle, int WriteZMode /* DX_ZWRITE_MASK 等 */, const TCHAR *FormatString, ... ) ;												// Ｚバッフ?に対して書式指定文字列を?画する
extern	int			DrawExtendStringToZBuffer( int x, int y, double ExRateX, double ExRateY, const TCHAR *String, int WriteZMode /* DX_ZWRITE_MASK 等 */ ) ;													// Ｚバッフ?に対して文字列の拡大?画
extern	int			DrawExtendVStringToZBuffer( int x, int y, double ExRateX, double ExRateY, const TCHAR *String, int WriteZMode /* DX_ZWRITE_MASK 等 */ ) ;													// Ｚバッフ?に対して文字列の拡大?画
extern	int			DrawExtendStringToHandleToZBuffer( int x, int y, double ExRateX, double ExRateY, const TCHAR *String, int FontHandle, int WriteZMode /* DX_ZWRITE_MASK 等 */ , int VerticalFlag = FALSE ) ;	// Ｚバッフ?に対して文字列を拡大?画する
extern	int			DrawExtendVStringToHandleToZBuffer( int x, int y, double ExRateX, double ExRateY, const TCHAR *String, int FontHandle, int WriteZMode /* DX_ZWRITE_MASK 等 */ ) ;							// Ｚバッフ?に対して文字列を拡大?画する
extern	int			DrawExtendFormatStringToZBuffer( int x, int y, double ExRateX, double ExRateY, int WriteZMode /* DX_ZWRITE_MASK 等 */, const TCHAR *FormatString, ... ) ;									// Ｚバッフ?に対して書式指定文字列を拡大?画する
extern	int			DrawExtendFormatVStringToZBuffer( int x, int y, double ExRateX, double ExRateY, int WriteZMode /* DX_ZWRITE_MASK 等 */, const TCHAR *FormatString, ... ) ;									// Ｚバッフ?に対して書式指定文字列を拡大?画する
extern	int			DrawExtendFormatStringToHandleToZBuffer( int x, int y, double ExRateX, double ExRateY, int FontHandle, int WriteZMode /* DX_ZWRITE_MASK 等 */, const TCHAR *FormatString, ... ) ;			// Ｚバッフ?に対して書式指定文字列を拡大?画する
extern	int			DrawExtendFormatVStringToHandleToZBuffer( int x, int y, double ExRateX, double ExRateY, int FontHandle, int WriteZMode /* DX_ZWRITE_MASK 等 */, const TCHAR *FormatString, ... ) ;			// Ｚバッフ?に対して書式指定文字列を拡大?画する
extern	int			DrawPolygonBase( VERTEX *Vertex, int VertexNum, int PrimitiveType /* DX_PRIMTYPE_TRIANGLELIST 等 */, int GrHandle, int TransFlag, int UVScaling = FALSE ) ;									// ２Ｄ?リゴンを?画する
extern	int			DrawPolygon( VERTEX *Vertex, int PolygonNum, int GrHandle, int TransFlag, int UVScaling = FALSE ) ;																							// ２Ｄ?リゴンを?画する
extern	int			DrawPrimitive2D( VERTEX2D *Vertex, int VertexNum, int PrimitiveType /* DX_PRIMTYPE_TRIANGLELIST 等 */, int GrHandle, int TransFlag ) ;														// ２Ｄプリ?ティブを?画する
extern	int			DrawPrimitiveIndexed2D( VERTEX2D *Vertex, int VertexNum, unsigned short *Indices, int IndexNum, int PrimitiveType /* DX_PRIMTYPE_TRIANGLELIST 等 */, int GrHandle, int TransFlag ) ;		// ２Ｄプリ?ティブを?画する(インデックス)
extern	int			DrawPrimitive3D( VERTEX3D *Vertex, int VertexNum, int PrimitiveType /* DX_PRIMTYPE_TRIANGLELIST 等 */, int GrHandle, int TransFlag ) ;														// ３Ｄプリ?ティブを?画する
extern	int			DrawPrimitiveIndexed3D( VERTEX3D *Vertex, int VertexNum, unsigned short *Indices, int IndexNum, int PrimitiveType /* DX_PRIMTYPE_TRIANGLELIST 等 */, int GrHandle, int TransFlag ) ;		// ３Ｄプリ?ティブを?画する(インデックス)
extern	int			DrawPrimitive3D_UseVertexBuffer( int VertexBufHandle, int PrimitiveType  /* DX_PRIMTYPE_TRIANGLELIST 等 */, int GrHandle, int TransFlag ) ;													// 頂?バッフ?を使用して３Ｄプリ?ティブを?画する
extern	int			DrawPrimitive3D_UseVertexBuffer2( int VertexBufHandle, int PrimitiveType  /* DX_PRIMTYPE_TRIANGLELIST 等 */, int StartVertex, int UseVertexNum, int GrHandle, int TransFlag ) ;								// 頂?バッフ?を使用して３Ｄプリ?ティブを?画する
extern	int			DrawPrimitiveIndexed3D_UseVertexBuffer( int VertexBufHandle, int IndexBufHandle, int PrimitiveType  /* DX_PRIMTYPE_TRIANGLELIST 等 */, int GrHandle, int TransFlag ) ;						// 頂?バッフ?とインデックスバッフ?を使用して３Ｄプリ?ティブを?画する
extern	int			DrawPrimitiveIndexed3D_UseVertexBuffer2( int VertexBufHandle, int IndexBufHandle, int PrimitiveType  /* DX_PRIMTYPE_TRIANGLELIST 等 */, int BaseVertex, int StartVertex, int UseVertexNum, int StartIndex, int UseIndexNum, int GrHandle, int TransFlag ) ;						// 頂?バッフ?とインデックスバッフ?を使用して３Ｄプリ?ティブを?画する
extern	int			DrawPolygon3D( VERTEX3D *Vertex, int PolygonNum, int GrHandle, int TransFlag ) ;																	// ３Ｄ?リゴンを?画する
extern	int			DrawPolygonIndexed3D( VERTEX3D *Vertex, int VertexNum, unsigned short *Indices, int PolygonNum, int GrHandle, int TransFlag ) ;						// ３Ｄ?リゴンを?画する(インデックス)
extern	int			DrawPolygon3D_UseVertexBuffer( int VertexBufHandle, int GrHandle, int TransFlag ) ;																	// 頂?バッフ?を使用して３Ｄ?リゴンを?画する
extern	int			DrawPolygonIndexed3D_UseVertexBuffer( int VertexBufHandle, int IndexBufHandle, int GrHandle, int TransFlag ) ;										// 頂?バッフ?とインデックスバッフ?を使用して３Ｄ?リゴンを?画する
extern	int			DrawPolygon3DBase( VERTEX_3D *Vertex, int VertexNum, int PrimitiveType /* DX_PRIMTYPE_TRIANGLELIST 等 */, int GrHandle, int TransFlag ) ;			// ３Ｄ?リゴンを?画する( 旧バ?ジョン用 )
extern	int			DrawPolygon3D( VERTEX_3D *Vertex, int PolygonNum, int GrHandle, int TransFlag ) ;																	// ３Ｄ?リゴンを?画する( 旧バ?ジョン用 )
extern	int			DrawGraph3D( float x, float y, float z, int GrHandle, int TransFlag ) ;																				// グラフィックの３Ｄ?画
extern	int			DrawExtendGraph3D( float x, float y, float z, double ExRateX, double ExRateY, int GrHandle, int TransFlag ) ;										// グラフィックの拡大３Ｄ?画
extern	int			DrawRotaGraph3D( float x, float y, float z, double ExRate, double Angle, int GrHandle, int TransFlag, int TurnFlag = FALSE ) ;						// グラフィックの回?３Ｄ?画
extern	int			DrawRota2Graph3D( float x, float y, float z, float cx, float cy, double ExtRateX, double ExtRateY, double Angle, int GrHandle, int TransFlag, int TurnFlag = FALSE ) ;	// グラフィックの回?３Ｄ?画(回?中心指定?)
extern	int			DrawModiBillboard3D( VECTOR Pos, float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, int GrHandle, int TransFlag ) ;	// グラフィックの自由変?３Ｄ?画
extern	int			DrawBillboard3D( VECTOR Pos, float cx, float cy, float Size, float Angle, int GrHandle, int TransFlag, int TurnFlag = FALSE ) ;						// ３Ｄ空間上にグラフィックを?画
extern	int			FillGraph( int GrHandle, int Red, int Green, int Blue, int Alpha = 255 ) ;																			// グラフィックを特定の色で塗りつぶす
extern	int			DrawLine( int x1, int y1, int x2, int y2, int Color, int Thickness = 1 ) ;																			// 線を?画
extern	int			DrawBox( int x1, int y1, int x2, int y2, int Color, int FillFlag ) ;																				// 四角?の?画
extern	int			DrawFillBox( int x1, int y1, int x2, int y2, int Color ) ;																							// 中身のある四角を?画
extern	int			DrawLineBox( int x1, int y1, int x2, int y2, int Color ) ;																							// 四角?の?画 
extern	int			DrawCircle( int x, int y, int r, int Color, int FillFlag = TRUE ) ;																					// ?を?く
extern	int			DrawOval( int x, int y, int rx, int ry, int Color, int FillFlag ) ;																					// 楕?を?く
extern	int			DrawTriangle( int x1, int y1, int x2, int y2, int x3, int y3, int Color, int FillFlag ) ;															// 三角?の?画
extern	int			DrawQuadrangle( int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int Color, int FillFlag ) ;											// 四角?の?画
extern 	int			DrawPixel( int x, int y, int Color ) ;																												// ?を?画する
extern 	int			DrawPixelSet( POINTDATA *PointData, int Num ) ;																										// ?の集合を?く
extern	int			DrawLineSet( LINEDATA *LineData, int Num ) ;																										// 線の集合を?く
extern	int			DrawPixel3D( VECTOR Pos, int Color ) ;																												// ３Ｄの?を?画する
extern	int			DrawLine3D( VECTOR Pos1, VECTOR Pos2, int Color ) ;																									// ３Ｄの線分を?画する
extern	int			DrawTriangle3D( VECTOR Pos1, VECTOR Pos2, VECTOR Pos3, int Color, int FillFlag ) ;																	// ３Ｄの三角?を?画する
extern	int			DrawCube3D( VECTOR Pos1, VECTOR Pos2, int DifColor, int SpcColor, int FillFlag ) ;																	// ３Ｄの立方体を?画する
extern	int			DrawSphere3D( VECTOR CenterPos, float r, int DivNum, int DifColor, int SpcColor, int FillFlag ) ;													// ３Ｄの球体を?画する
extern	int			DrawCapsule3D( VECTOR Pos1, VECTOR Pos2, float r, int DivNum, int DifColor, int SpcColor, int FillFlag ) ;											// ３Ｄのカプセルを?画する
extern	int			DrawCone3D( VECTOR TopPos, VECTOR BottomPos, float r, int DivNum, int DifColor, int SpcColor, int FillFlag ) ;										// ３Ｄの?錐を?画する
extern	int			DrawString( int x, int y, const TCHAR *String, int Color, int EdgeColor = 0 ) ;																		// 文字列の?画
extern	int			DrawVString( int x, int y, const TCHAR *String, int Color, int EdgeColor = 0 ) ;																		// 文字列の?画
extern	int			DrawStringToHandle( int x, int y, const TCHAR *String, int Color, int FontHandle, int EdgeColor = 0 , int VerticalFlag = FALSE ) ;					// 文字列を?画する
extern	int			DrawVStringToHandle( int x, int y, const TCHAR *String, int Color, int FontHandle, int EdgeColor = 0 ) ;												// 文字列を?画する
extern	int			DrawFormatString( int x, int y, int Color, const TCHAR *FormatString, ... ) ;																		// 書式指定文字列を?画する
extern	int			DrawFormatVString( int x, int y, int Color, const TCHAR *FormatString, ... ) ;																		// 書式指定文字列を?画する
extern	int			DrawFormatStringToHandle( int x, int y, int Color, int FontHandle, const TCHAR *FormatString, ... ) ;												// 書式指定文字列を?画する
extern	int			DrawFormatVStringToHandle( int x, int y, int Color, int FontHandle, const TCHAR *FormatString, ... ) ;												// 書式指定文字列を?画する
extern	int			DrawExtendString( int x, int y, double ExRateX, double ExRateY, const TCHAR *String, int Color, int EdgeColor = 0 ) ;													// 文字列の拡大?画
extern	int			DrawExtendVString( int x, int y, double ExRateX, double ExRateY, const TCHAR *String, int Color, int EdgeColor = 0 ) ;													// 文字列の拡大?画
extern	int			DrawExtendStringToHandle( int x, int y, double ExRateX, double ExRateY, const TCHAR *String, int Color, int FontHandle, int EdgeColor = 0 , int VerticalFlag = FALSE ) ;	// 文字列を拡大?画する
extern	int			DrawExtendVStringToHandle( int x, int y, double ExRateX, double ExRateY, const TCHAR *String, int Color, int FontHandle, int EdgeColor = 0 ) ;							// 文字列を拡大?画する
extern	int			DrawExtendFormatString( int x, int y, double ExRateX, double ExRateY, int Color, const TCHAR *FormatString, ... ) ;														// 書式指定文字列を拡大?画する
extern	int			DrawExtendFormatVString( int x, int y, double ExRateX, double ExRateY, int Color, const TCHAR *FormatString, ... ) ;														// 書式指定文字列を拡大?画する
extern	int			DrawExtendFormatStringToHandle( int x, int y, double ExRateX, double ExRateY, int Color, int FontHandle, const TCHAR *FormatString, ... ) ;								// 書式指定文字列を拡大?画する
extern	int			DrawExtendFormatVStringToHandle( int x, int y, double ExRateX, double ExRateY, int Color, int FontHandle, const TCHAR *FormatString, ... ) ;								// 書式指定文字列を拡大?画する

extern	int			DrawNumberToI( int x, int y, int Num, int RisesNum, int Color, int EdgeColor = 0 ) ;																// 整数?の数値を?画する
extern	int			DrawNumberToF( int x, int y, double Num, int Length, int Color, int EdgeColor = 0 ) ;																// 浮動小数??の数値を?画する
extern	int			DrawNumberPlusToI( int x, int y, const TCHAR *NoteString, int Num, int RisesNum, int Color, int EdgeColor = 0 ) ;									// 整数?の数値とその説明の文字列を一度に?画する
extern 	int			DrawNumberPlusToF( int x, int y, const TCHAR *NoteString, double Num, int Length, int Color, int EdgeColor = 0 ) ;									// 浮動小数??の数値とその説明の文字列を一度に?画する

extern	int			DrawNumberToIToHandle( int x, int y, int Num, int RisesNum, int Color, int FontHandle, int EdgeColor = 0 ) ;										// 整数?の数値を?画する
extern	int			DrawNumberToFToHandle( int x, int y, double Num, int Length, int Color, int FontHandle, int EdgeColor = 0 ) ;										// 浮動小数??の数値を?画する
extern	int			DrawNumberPlusToIToHandle( int x, int y, const TCHAR *NoteString, int Num, int RisesNum, int Color, int FontHandle, int EdgeColor = 0 ) ;			// 整数?の数値とその説明の文字列を一度に?画する
extern	int			DrawNumberPlusToFToHandle( int x, int y, const TCHAR *NoteString, double Num, int Length, int Color, int FontHandle, int EdgeColor = 0 ) ;			// 浮動小数??の数値とその説明の文字列を一度に?画する

// 頂?バッフ?関係関数
extern	int			CreateVertexBuffer( int VertexNum, int VertexType /* DX_VERTEX_TYPE_NORMAL_3D 等 */ ) ;																					// 頂?バッフ?を作成する( -1:エラ?  0以上:頂?バッフ?ハンドル )
extern	int			DeleteVertexBuffer( int VertexBufHandle ) ;																																// 頂?バッフ?を削除する
extern	int			InitVertexBuffer() ;																																					// すべての頂?バッフ?を削除する
extern	int			SetVertexBufferData( int SetIndex, void *VertexData, int VertexNum, int VertexBufHandle ) ;																				// 頂?バッフ?に頂?デ??を?送する
extern	int			CreateIndexBuffer( int IndexNum, int IndexType /* DX_INDEX_TYPE_16BIT 等 */  ) ;																						// インデックスバッフ?を作成する( -1:エラ??0以上：インデックスバッフ?ハンドル )
extern	int			DeleteIndexBuffer( int IndexBufHandle ) ;																																// インデックスバッフ?を削除する
extern	int			InitIndexBuffer() ;																																						// すべてのインデックスバッフ?を削除する
extern	int			SetIndexBufferData( int SetIndex, void *IndexData, int IndexNum, int IndexBufHandle ) ;																					// インデックスバッフ?にインデックスデ??を?送する

#ifndef DX_NON_DIRECTX9

// シェ???関係関数
extern	int			GetValidShaderVersion( void ) ;										// 使用できるシェ???のバ?ジョンを取得する( 0=使えない  200=シェ???モデル２．０が使用可?  300=シェ???モデル３．０が使用可? )

extern	int			LoadVertexShader( const TCHAR *FileName ) ;							// 頂?シェ???バイナリをフ?イルから読み込み頂?シェ???ハンドルを作成する( 戻り値 -1:エラ?  -1以外:シェ???ハンドル )
extern	int			LoadVertexShaderFromMem( void *ImageAddress, int ImageSize ) ;		// メモリ空間上に存在する頂?シェ???バイナリから頂?シェ???ハンドルを作成する( 戻り値 -1:エラ?  -1以外:シェ???ハンドル )
extern	int			LoadPixelShader( const TCHAR *FileName ) ;							// ピクセルシェ???バイナリをフ?イルから読み込みピクセルシェ???ハンドルを作成する( 戻り値 -1:エラ?  -1以外:シェ???ハンドル )
extern	int			LoadPixelShaderFromMem( void *ImageAddress, int ImageSize ) ;		// メモリ空間上に存在するピクセルシェ???バイナリからピクセルシェ???ハンドルを作成する( 戻り値 -1:エラ?  -1以外:シェ???ハンドル )
extern	int			DeleteShader( int ShaderHandle ) ;									// シェ???ハンドルの削除
extern	int			InitShader( void ) ;												// シェ???ハンドルを全て削除する

extern	int			GetConstIndexToShader( const TCHAR *ConstantName, int ShaderHandle ) ;		// 指定の名前を持つ定数の番号を取得する
extern	int			SetVSConstF( int ConstantIndex, FLOAT4 Param ) ;							// 頂?シェ???の float ?定数を設定する
extern	int			SetVSConstFMtx( int ConstantIndex, MATRIX Param ) ;							// 頂?シェ???の float ?定数に行列を設定する
extern	int			SetVSConstI( int ConstantIndex, INT4 Param ) ;								// 頂?シェ???の int ?定数を設定する
extern	int			SetVSConstB( int ConstantIndex, BOOL Param ) ;								// 頂?シェ???の BOOL ?定数を設定する
extern	int			SetVSConstFArray( int ConstantIndex, FLOAT4 *ParamArray, int ParamNum ) ;	// 頂?シェ???の float ?定数を設定する( 配列を使って連番インデックスに一度に設定 )
extern	int			SetVSConstFMtxArray( int ConstantIndex, MATRIX *ParamArray, int ParamNum ) ; // 頂?シェ???の float ?定数に行列を設定する( 配列を使って連番インデックスに一度に設定 )
extern	int			SetVSConstIArray( int ConstantIndex, INT4 *ParamArray, int ParamNum ) ;		// 頂?シェ???の int ?定数を設定する( 配列を使って連番インデックスに一度に設定 )
extern	int			SetVSConstBArray( int ConstantIndex, BOOL *ParamArray, int ParamNum ) ;		// 頂?シェ???の BOOL ?定数を設定する( 配列を使って連番インデックスに一度に設定 )

extern	int			SetPSConstF( int ConstantIndex, FLOAT4 Param ) ;							// ピクセルシェ???の float ?定数を設定する
extern	int			SetPSConstFMtx( int ConstantIndex, MATRIX Param ) ;							// ピクセルシェ???の float ?定数に行列を設定する
extern	int			SetPSConstI( int ConstantIndex, INT4 Param ) ;								// ピクセルシェ???の int ?定数を設定する
extern	int			SetPSConstB( int ConstantIndex, BOOL Param ) ;								// ピクセルシェ???の BOOL ?定数を設定する
extern	int			SetPSConstFArray( int ConstantIndex, FLOAT4 *ParamArray, int ParamNum ) ;	// ピクセルシェ???の float ?定数を設定する( 配列を使って連番インデックスに一度に設定 )
extern	int			SetPSConstFMtxArray( int ConstantIndex, MATRIX *ParamArray, int ParamNum ) ; // ピクセルシェ???の float ?定数に行列を設定する( 配列を使って連番インデックスに一度に設定 )
extern	int			SetPSConstIArray( int ConstantIndex, INT4 *ParamArray, int ParamNum ) ;		// ピクセルシェ???の int ?定数を設定する( 配列を使って連番インデックスに一度に設定 )
extern	int			SetPSConstBArray( int ConstantIndex, BOOL *ParamArray, int ParamNum ) ;		// ピクセルシェ???の BOOL ?定数を設定する( 配列を使って連番インデックスに一度に設定 )

//extern int		SetRenderTargetToShader( int TargetIndex, int DrawScreen ) ;		// シェ????画での?画先を設定する
extern	int			SetUseTextureToShader( int StageIndex, int GraphHandle ) ;			// シェ????画で使用するグラフィックを設定する
extern	int			SetUseVertexShader( int ShaderHandle ) ;							// シェ????画に使用する頂?シェ???を設定する( -1を渡すと解除 )
extern	int			SetUsePixelShader( int ShaderHandle ) ;								// シェ????画に使用するピクセルシェ???を設定する( -1を渡すと解除 )

extern	int			DrawPrimitive2DToShader( VERTEX2DSHADER *Vertex, int VertexNum, int PrimitiveType ) ;												// シェ???を使って２Ｄプリ?ティブを?画する
extern	int			DrawPrimitive3DToShader( VERTEX3DSHADER *Vertex, int VertexNum, int PrimitiveType ) ;												// シェ???を使って３Ｄプリ?ティブを?画する
extern	int			DrawPrimitiveIndexed2DToShader( VERTEX2DSHADER *Vertex, int VertexNum, unsigned short *Indices, int IndexNum, int PrimitiveType ) ;	// シェ???を使って２Ｄプリ?ティブを?画する(インデックス)
extern	int			DrawPrimitiveIndexed3DToShader( VERTEX3DSHADER *Vertex, int VertexNum, unsigned short *Indices, int IndexNum, int PrimitiveType ) ;	// シェ???を使って３Ｄプリ?ティブを?画する(インデックス)

#endif // DX_NON_DIRECTX9

// ３Ｄ?画関係関数
//extern void			SetColorVertexState( LPVERTEXDATA Vertex, float x, float y, float z, float rhw, int red, int green, int blue, int alpha, float tu, float tv ) ;	// ３Ｄ頂?デ??をセットする  

// ?画設定関係関数
extern	int			SetDrawMode( int DrawMode ) ;										// ?画モ?ドをセットする
extern	int			SetMaxAnisotropy( int MaxAnisotropy ) ;								// 最大異方性の値をセットする
extern	int			SetDrawBlendMode( int BlendMode, int BlendParam ) ;					// ?画ブレンドモ?ドをセットする
extern	int			SetDrawAlphaTest( int TestMode, int TestParam ) ;					// ?画時のアルフ?テストの設定を行う( TestMode:DX_CMP_GREATER等( -1:デフォルト動作に戻す )  TestParam:?画アルフ?値との比較に使用する値 )
extern	int			SetBlendGraph( int BlendGraph, int BorderParam, int BorderRange ) ;	// ?画処理時に?画する画像とブレンドするα?ャンネル付き画像をセットする( BlendGraph を -1 でブレンド??を無効 )
extern	int			SetBlendGraphPosition( int x, int y ) ;								// ブレンド画像の起?座標をセットする
extern	int			SetDrawBright( int RedBright, int GreenBright, int BlueBright ) ;	// ?画輝度をセット
extern	int			SetDrawScreen( int DrawScreen ) ;									// ?画先画面のセット
extern	int			SetDrawArea( int x1, int y1, int x2, int y2 ) ;						// ?画可?領域のセット
extern	int			SetDraw3DScale( float Scale ) ;										// ３Ｄ?画のスケ?ルをセットする
extern	int			SetDrawAreaFull( void ) ;											// ?画可?領域を?画対象画面全体にする
extern	int			SetUse3DFlag( int Flag ) ;											// ３Ｄ??を使うか、のフラグをセット
extern	int			SetUseHardwareVertexProcessing( int Flag ) ;						// ハ?ドウエアの頂?演算処理??を使用するかどうかを設定する
extern	int			SetRestoreShredPoint( void (* ShredPoint )( void ) ) ;				// SetRestoreGraphCallback の旧名
extern	int			SetRestoreGraphCallback( void (* Callback )( void ) ) ;				// グラフィックハンドル復元関数の登?
extern	int			RunRestoreShred( void ) ;											// グラフィック復元関数の実行
extern	int			SetGraphicsDeviceRestoreCallbackFunction( void (* Callback )( void *Data ), void *CallbackData ) ;	// グラフィックスデバイスがロストから復帰した際に呼ばれるコ?ルバック関数を設定する
extern	int			SetTransformToWorld( MATRIX *Matrix ) ;								// ワ?ルド変換用行列をセットする
extern	int			SetTransformToView( MATRIX *Matrix ) ;								// ビュ?変換用行列をセットする
extern	int			SetTransformToProjection( MATRIX *Matrix ) ;						// 投影変換用行列をセットする
extern	int			SetTransformToViewport( MATRIX *Matrix ) ;							// ビュ???ト行列をセットする
extern	int			SetUseCullingFlag( int Flag ) ;										// SetUseBackCulling の旧名称
extern	int			SetUseBackCulling( int Flag /* DX_CULLING_LEFT 等 */ ) ;			// ?リゴンカリングの有効、無効をセットする
extern	int			SetTextureAddressMode( int Mode /* DX_TEXADDRESS_WRAP 等 */ , int Stage = -1 ) ;		// テクス?ャアドレスモ?ドを設定する
extern	int			SetTextureAddressModeUV( int ModeU, int ModeV, int Stage = -1 ) ;	// テクス?ャアドレスモ?ドを設定する
extern	int			SetTextureAddressTransform( float TransU, float TransV, float ScaleU, float ScaleV, float RotCenterU, float RotCenterV, float Rotate ) ;	// テクス?ャ座標変換パラメ??をセットする
extern	int			SetTextureAddressTransformMatrix( MATRIX Matrix ) ;					// テクス?ャ座標変換行列をセットする
extern	int			ResetTextureAddressTransform( void ) ;								// テクス?ャ座標変換パラメ??をリセットする
extern	int			SetFogEnable( int Flag ) ;											// フォグを有効にするかどうかを設定する( TRUE:有効  FALSE:無効 )
extern	int			SetFogMode( int Mode /* DX_FOGMODE_NONE 等 */ ) ;					// フォグモ?ドを設定する
extern	int			SetFogColor( int r, int g, int b ) ;								// フォグカラ?を変更する
extern	int			SetFogStartEnd( float start, float end ) ;							// フォグが始まる距離と終了する距離を設定する( 0.0f ? 1.0f )
extern	int			SetFogDensity( float density ) ;									// フォグの密度を設定する( 0.0f ? 1.0f )
extern	int			SetUseSystemMemGraphCreateFlag( int Flag ) ;						// システ?メモリ上にグラフィックを作成するかどうかのフラグをセットする( TRUE:システ?メモリ上に作成  FALSE:ＶＲ?Ｍ上に作成 )
extern	int			SetUseVramFlag( int Flag ) ;										// ＶＲ?Ｍを使用するかのフラグをセットする
extern	int			RestoreGraphSystem( void ) ;										// ＤＸライブラリのグラフィック関連の復帰処理を行う
extern	int			SetAeroDisableFlag( int Flag ) ;									// Vista以?の Windows Aero を無効にするかどうかをセットする、TRUE:無効にする  FALSE:有効にする( DxLib_Init の前に呼ぶ必要があります )

// グラフィック情報取得関係関数

//extern	int			GetGraphHandle( IMAGEDATA *GraphData ) ;													// 自分のグラフィックインデックス番号を取得する
//extern	IMAGEDATA 	*GetGraphData( int GrHandle ) ;																// グラフィックのデ??をインデックス値から取り出す

extern	int			GetDrawScreenGraph( int x1, int y1, int x2, int y2, int GrHandle, int UseClientFlag = TRUE ) ;	// アクティブになっている画面から指定領域のグラフィックを取得する
extern	DWORD*		GetFullColorImage( int GrHandle ) ;																// 指定の画像の?ＲＧＢ８のフルカラ?イメ?ジを取得する

extern	int			GraphLock( int GrHandle, int *PitchBuf, void **DataPointBuf, COLORDATA **ColorDataPP = NULL ) ;	// グラフィックメモリ領域のロック
extern	int			GraphUnLock( int GrHandle ) ;																	// グラフィックメモリ領域のロック解除

extern	int			SetUseGraphZBuffer( int GrHandle, int UseFlag ) ;												// グラフィックにＺバッフ?を使用するかどうかを設定する

extern	int			GetGraphSize( int GrHandle, int *SizeXBuf, int *SizeYBuf ) ;									// グラフィックのサイズを得る
extern	int			GetScreenState( int *SizeX, int *SizeY, int *ColorBitDepth ) ;									// 現在の画面の大きさとカラ?ビット数を得る 
extern	int			GetUse3DFlag( void ) ;																			// ?画に３Ｄ??を使うかフラグを取得
extern	int			GetValidRestoreShredPoint( void ) ;																// グラフィック復元関数の有無を取得																
extern	int			GetTransformToViewMatrix( MATRIX *MatBuf ) ;													// ビュ?行列を取得する
extern	int			GetTransformToWorldMatrix( MATRIX *MatBuf ) ;													// ワ?ルド行列を取得する
extern	int			GetTransformToProjectionMatrix( MATRIX *MatBuf ) ;												// 射影行列を取得する
extern	int			GetTransformPosition( VECTOR *LocalPos, float *x, float *y ) ;									// ロ?カル座標から画面座標を取得する
extern	float		GetBillboardPixelSize( VECTOR WorldPos, float WorldSize ) ;										// ワ?ルド空間上のビル??ドのサイズからスクリ?ンに投影した場合のピクセル単位のサイズを取得する
extern	VECTOR		ConvWorldPosToScreenPos( VECTOR WorldPos ) ;													// ワ?ルド座標をスクリ?ン座標に変換する
extern	VECTOR		ConvScreenPosToWorldPos( VECTOR ScreenPos ) ;													// スクリ?ン座標をワ?ルド座標に変換する
extern	VECTOR		ConvScreenPosToWorldPos_ZLinear( VECTOR ScreenPos ) ;											// スクリ?ン座標をワ?ルド座標に変換する( Z座標が線? )
extern	int			GetUseVramFlag( void ) ;																		// ２Ｄグラフィックサ?フェス作成時にシステ?メモリ?を使用するかのフラグ取得

// 補助関係
extern	int			GetCreateGraphColorData( COLORDATA *ColorData, IMAGEFORMATDESC *Format ) ;									// これから新たにグラフィックを作成する場合に使用するカラ?情報を取得する

// 画像作成用関係
//extern int		SetGraphName( int Handle, const char *GraphName ) ;																																																// 特定のフ?イルから画像を読み込んだ場合のフ?イルパスをセットする
extern	int			CreateDXGraph( BASEIMAGE *RgbImage, BASEIMAGE *AlphaImage, int TextureFlag ) ;																																									// GraphImage デ??からサイズを割り出し、それに合ったグラフィックハンドルを作成する
//extern int		CreateDXDivGraph( BASEIMAGE *RgbImage, BASEIMAGE *AlphaImage, int AllNum, int XNum, int YNum, int SizeX, int SizeY, int *HandleBuf, int TextureFlag ) ;																							// GraphImage デ??に合ったサイズの分割グラフィックハンドルを作成する
extern	int			DerivationGraph( int SrcX, int SrcY, int Width, int Height, int SrcGraphHandle ) ;																																								// 指定のグラフィックの指定部分だけを抜き出して新たなグラフィックハンドルを作成する

#ifndef DX_NON_MOVIE
// ??ビ?グラフィック関係関数
extern	int			PlayMovie( const TCHAR *FileName, int ExRate, int PlayType ) ;								// 動画フ?イルの再生
extern	int			OpenMovieToGraph( const TCHAR *FileName, int FullColor = TRUE ) ;							// ??ビ?を開く
extern 	int			PlayMovieToGraph( int GraphHandle, int PlayType = DX_PLAYTYPE_BACK , int SysPlay = 0 ) ;	// ??ビ?グラフィックに含まれる??ビ?の再生を開始する
extern 	int			PauseMovieToGraph( int GraphHandle, int SysPause = 0 ) ;									// ??ビ?グラフィックに含まれる??ビ?の再生をストップする
extern	int			AddMovieFrameToGraph( int GraphHandle, unsigned int FrameNum ) ;							// ??ビ?のフレ??を進める、戻すことは出来ない( ??ビ?が停?状態で、且つ Ogg Theora のみ有効 )
extern	int			SeekMovieToGraph( int GraphHandle, int Time ) ;												// ??ビ?の再生位置を設定する(?リ秒単位)
extern 	int			GetMovieStateToGraph( int GraphHandle ) ;													// ??ビ?の再生状態を得る
extern	int			SetMovieVolumeToGraph( int Volume, int GraphHandle ) ;										// ??ビ?の?リュ??をセットする(0?10000)
extern	BASEIMAGE*	GetMovieBaseImageToGraph( int GraphHandle ) ;												// ??ビ?の基?イメ?ジデ??を取得する
extern	int			GetMovieTotalFrameToGraph( int GraphHandle ) ;												// ??ビ?の総フレ??数を得る( Ogg Theora でのみ有効 )
extern	int			TellMovieToGraph( int GraphHandle ) ;														// ??ビ?の再生位置を取得する(?リ秒単位)
extern	int			TellMovieToGraphToFrame( int GraphHandle ) ;												// ??ビ?の再生位置を取得する(フレ??単位)
extern	int			SeekMovieToGraphToFrame( int GraphHandle, int Frame ) ;										// ??ビ?の再生位置を設定する(フレ??単位)
extern	LONGLONG	GetOneFrameTimeMovieToGraph( int GraphHandle ) ;											// ??ビ?の１フレ??あたりの時間を得る
extern	int			GetLastUpdateTimeMovieToGraph( int GraphHandle ) ;											// ??ビ?のイメ?ジを最後に更新した時間を得る(?リ秒単位)

#endif








// DxGraphicsBase.cpp 関数プロト?イプ宣言

// グラフィックハンドル作成系
extern	int			LoadBmpToGraph( const TCHAR *GraphName, int TextureFlag, int ReverseFlag, int SurfaceMode = DX_MOVIESURFACE_NORMAL ) ;										// 画像を読みこむ 
extern	int			LoadGraph( const TCHAR *FileName, int NotUse3DFlag = FALSE ) ;																								// 画像フ?イルのメモリへの読みこみ
extern	int			LoadReverseGraph( const TCHAR *FileName, int NotUse3DFlag = FALSE ) ;																						// 画像フ?イルのメモリへの反?読み込み
extern	int			LoadDivGraph( const TCHAR *FileName, int AllNum, int XNum, int YNum, int XSize, int YSize, int *HandleBuf, int NotUse3DFlag = FALSE ) ;						// 画像の分割読みこみ
extern	int			LoadDivBmpToGraph( const TCHAR *FileName, int AllNum, int XNum, int YNum, int SizeX, int SizeY, int *HandleBuf, int TextureFlag, int ReverseFlag ) ;			// 画像フ?イルの分割読みこみ
extern	int			LoadReverseDivGraph( const TCHAR *FileName, int AllNum, int XNum, int YNum, int XSize, int YSize, int *HandleBuf, int NotUse3DFlag = FALSE ) ;				// 画像の反?分割読みこみ
extern	int			LoadBlendGraph( const TCHAR *FileName ) ;																													// 画像フ?イルからブレンド用画像を読み込む
extern	int			LoadGraphToResource( int ResourceID ) ;																														// リ??スから画像デ??を読み込む
extern	int			LoadDivGraphToResource( int ResourceID, int AllNum, int XNum, int YNum, int XSize, int YSize, int *HandleBuf ) ;											// リ??スから画像デ??を分割読み込みする
extern	int			LoadGraphToResource( const TCHAR *ResourceName, const TCHAR *ResourceType ) ;																					// リ??スから画像デ??を読み込む
extern	int			LoadDivGraphToResource( const TCHAR *ResourceName, const TCHAR *ResourceType, int AllNum, int XNum, int YNum, int XSize, int YSize, int *HandleBuf ) ;		// リ??スから画像デ??を分割読み込みする

extern	int			CreateGraphFromMem( void *MemImage, int MemImageSize, void *AlphaImage = NULL , int AlphaImageSize = 0 , int TextureFlag = TRUE , int ReverseFlag = FALSE ) ;																						// メモリ上のグラフィックイメ?ジからグラフィックハンドルを作成する
extern	int			ReCreateGraphFromMem( void *MemImage, int MemImageSize, int GrHandle, void *AlphaImage = NULL , int AlphaImageSize = 0 , int TextureFlag = TRUE , int ReverseFlag = FALSE ) ;																		// メモリ上のグラフィックイメ?ジから既存のグラフィックハンドルにデ??を?送する
extern	int			CreateDivGraphFromMem( void *MemImage, int MemImageSize, int AllNum, int XNum, int YNum, int SizeX, int SizeY, int *HandleBuf, int TextureFlag = TRUE , int ReverseFlag = FALSE , void *AlphaImage = NULL , int AlphaImageSize = 0 ) ;				// メモリ上のグラフィックイメ?ジから分割グラフィックハンドルを作成する
extern	int			ReCreateDivGraphFromMem( void *MemImage, int MemImageSize, int AllNum, int XNum, int YNum, int SizeX, int SizeY, int *HandleBuf, int TextureFlag = TRUE , int ReverseFlag = FALSE , void *AlphaImage = NULL , int AlphaImageSize = 0 ) ;			// メモリ上のグラフィックイメ?ジから既存の分割グラフィックハンドルにデ??を?送する
extern	int			CreateGraphFromBmp( BITMAPINFO *BmpInfo, void *GraphData, BITMAPINFO *AlphaInfo = NULL , void *AlphaData = NULL , int TextureFlag = TRUE , int ReverseFlag = FALSE ) ;																				// ビット?ップデ??からグラフィックハンドルを作成する
extern	int			ReCreateGraphFromBmp( BITMAPINFO *BmpInfo, void *GraphData, int GrHandle, BITMAPINFO *AlphaInfo = NULL , void *AlphaData = NULL , int TextureFlag = TRUE , int ReverseFlag = FALSE ) ;																// ビット?ップデ??から既存のグラフィックハンドルにデ??を?送する
extern	int			CreateDivGraphFromBmp( BITMAPINFO *BmpInfo, void *GraphData, int AllNum, int XNum, int YNum, int SizeX, int SizeY, int *HandleBuf, int TextureFlag = TRUE , int ReverseFlag = FALSE , BITMAPINFO *AlphaInfo = NULL , void *AlphaData = NULL ) ;		// ビット?ップデ??から分割グラフィックハンドルを作成する
extern	int			ReCreateDivGraphFromBmp( BITMAPINFO *BmpInfo, void *GraphData, int AllNum, int XNum, int YNum, int SizeX, int SizeY, int *HandleBuf, int TextureFlag = TRUE , int ReverseFlag = FALSE , BITMAPINFO *AlphaInfo = NULL , void *AlphaData = NULL ) ;	// ビット?ップデ??から既存の分割グラフィックハンドルにデ??を?送する
extern	int			CreateGraphFromGraphImage( BASEIMAGE *Image, int TextureFlag = TRUE , int ReverseFlag = FALSE , int DataReverseFlag = TRUE ) ;																														// GraphImageデ??からグラフィックハンドルを作成する
extern	int			CreateGraphFromGraphImage( BASEIMAGE *Image, BASEIMAGE *AlphaImage, int TextureFlag = TRUE , int ReverseFlag = FALSE , int DataReverseFlag = TRUE ) ;																								// GraphImageデ??からグラフィックハンドルを作成する
extern	int			ReCreateGraphFromGraphImage( BASEIMAGE *Image, int GrHandle, int TextureFlag = TRUE , int ReverseFlag = FALSE , int DataReverseFlag = TRUE ) ;																										// GraphImageデ??から既存のグラフィックハンドルにデ??を?送する
extern	int			ReCreateGraphFromGraphImage( BASEIMAGE *Image, BASEIMAGE *AlphaImage, int GrHandle, int TextureFlag = TRUE , int ReverseFlag = FALSE , int DataReverseFlag = TRUE ) ;																				// GraphImageデ??から既存のグラフィックハンドルにデ??を?送する
extern	int			CreateDivGraphFromGraphImage( BASEIMAGE *Image, int AllNum, int XNum, int YNum, int SizeX, int SizeY, int *HandleBuf, int TextureFlag = TRUE , int ReverseFlag = FALSE , int DataReverseFlag = TRUE ) ;												// GraphImageデ??から分割グラフィックハンドルを作成する
extern	int			CreateDivGraphFromGraphImage( BASEIMAGE *Image, BASEIMAGE *AlphaImage, int AllNum, int XNum, int YNum, int SizeX, int SizeY, int *HandleBuf, int TextureFlag = TRUE , int ReverseFlag = FALSE , int DataReverseFlag = TRUE ) ;						// GraphImageデ??から分割グラフィックハンドルを作成する
extern	int			ReCreateDivGraphFromGraphImage( BASEIMAGE *Image, int AllNum, int XNum, int YNum, int SizeX, int SizeY, int *HandleBuf, int TextureFlag = TRUE , int ReverseFlag = FALSE , int DataReverseFlag = TRUE ) ;											// GraphImageデ??から既存の分割グラフィックハンドルにデ??を?送する
extern	int			ReCreateDivGraphFromGraphImage( BASEIMAGE *Image, BASEIMAGE *AlphaImage, int AllNum, int XNum, int YNum, int SizeX, int SizeY, int *HandleBuf, int TextureFlag = TRUE , int ReverseFlag = FALSE , int DataReverseFlag = TRUE ) ;					// GraphImageデ??から既存の分割グラフィックハンドルにデ??を?送する
extern	int			CreateGraph( int Width, int Height, int Pitch, void *GraphData, void *AlphaData = NULL , int GrHandle = -1 ) ;																																		// メモリ上のグラフィックデ??からグラフィックハンドルを作成する
extern	int			CreateDivGraph( int Width, int Height, int Pitch, void *GraphData, int AllNum, int XNum, int YNum, int SizeX, int SizeY, int *HandleBuf, void *AlphaData = NULL ) ;																					// メモリ上のグラフィックデ??から分割グラフィックハンドルを作成する
extern	int			ReCreateGraph( int Width, int Height, int Pitch, void *GraphData, int GrHandle, void *AlphaData = NULL ) ;																																			// メモリ上のグラフィックデ??からグラフィックハンドルを再作成する
extern	int			CreateBlendGraphFromSoftImage( int SIHandle ) ;																												// ?フトウエアで扱うイメ?ジからブレンド用画像グラフィックハンドルを作成する( -1:エラ?  -1以外:ブレンド用グラフィックハンドル )
extern	int			CreateGraphFromSoftImage( int SIHandle ) ;																													// ?フトウエアで扱うイメ?ジからグラフィックハンドルを作成する( -1:エラ?  -1以外:グラフィックハンドル )
extern	int			CreateGraphFromRectSoftImage( int SIHandle, int x, int y, int SizeX, int SizeY ) ;																			// ?フトウエアで扱うイメ?ジの指定の領域を使ってグラフィックハンドルを作成する( -1:エラ?  -1以外:グラフィックハンドル )
extern	int			ReCreateGraphFromSoftImage( int SIHandle, int GrHandle ) ;																									// ?フトウエアで扱うイメ?ジから既存のグラフィックハンドルに画像デ??を?送する
extern	int			ReCreateGraphFromRectSoftImage( int SIHandle, int x, int y, int SizeX, int SizeY, int GrHandle ) ;															// ?フトウエアで扱うイメ?ジから既存のグラフィックハンドルに画像デ??を?送する
extern	int			CreateDivGraphFromSoftImage( int SIHandle, int AllNum, int XNum, int YNum, int SizeX, int SizeY, int *HandleBuf ) ;											// ?フトウエアで扱うイメ?ジから分割グラフィックハンドルを作成する
extern	int			CreateGraphFromBaseImage( BASEIMAGE *BaseImage ) ;																											// 基?イメ?ジデ??からグラフィックハンドルを作成する
extern	int			CreateGraphFromRectBaseImage( BASEIMAGE *BaseImage, int x, int y, int SizeX, int SizeY ) ;																	// 基?イメ?ジの指定の領域を使ってグラフィックハンドルを作成する
extern	int			ReCreateGraphFromBaseImage( BASEIMAGE *BaseImage, int GrHandle ) ;																							// 基?イメ?ジデ??から既存のグラフィックハンドルに画像デ??を?送する
extern	int			ReCreateGraphFromRectBaseImage( BASEIMAGE *BaseImage, int x, int y, int SizeX, int SizeY, int GrHandle ) ;													// 基?イメ?ジの指定の領域を使って既存のグラフィックハンドルに画像デ??を?送する
extern	int			CreateDivGraphFromBaseImage( BASEIMAGE *BaseImage, int AllNum, int XNum, int YNum, int SizeX, int SizeY, int *HandleBuf ) ;									// 基?イメ?ジデ??から分割グラフィックハンドルを作成する
extern	int			ReloadGraph( const TCHAR *FileName, int GrHandle, int ReverseFlag = FALSE ) ;																				// 画像への画像デ??の読み込み
extern	int			ReloadDivGraph( const TCHAR *FileName, int AllNum, int XNum, int YNum, int XSize, int YSize, int *HandleBuf, int ReverseFlag = FALSE ) ;						// 画像への画像デ??の分割読み込み
extern	int			ReloadReverseGraph( const TCHAR *FileName, int GrHandle ) ;																									// 画像への画像デ??の読み込み
extern	int			ReloadReverseDivGraph( const TCHAR *FileName, int AllNum, int XNum, int YNum, int XSize, int YSize, int *HandleBuf ) ;										// 画像への画像デ??の分割読み込み

// 基?イメ?ジ?画
extern	int			DrawBaseImage( int x, int y, BASEIMAGE *BaseImage ) ;																																															// 基?イメ?ジデ??を?画する

// カメラ関係関数
extern	int			SetCameraNearFar( float Near, float Far ) ;																			// カメラの Nearクリップ面と Farクリップ面の距離を設定する
extern	int			SetCameraPositionAndTarget_UpVecY( VECTOR Position, VECTOR Target ) ;												// カメラの設定をする、視?、注視?、アップベクトルはＹ軸版
extern	int			SetCameraPositionAndTargetAndUpVec( VECTOR Position, VECTOR Target, VECTOR Up ) ;									// カメラの設定をする、視?、注視?、アップベクトル指定版
extern	int			SetCameraPositionAndAngle( VECTOR Position, float VRotate, float HRotate, float TRotate ) ;							// カメラの設定をする、垂直回?角度、水平回?角度、捻り回?角度、視?指定版
extern	int			SetCameraViewMatrix( MATRIX ViewMatrix ) ;																			// ビュ?行列を直接設定する
extern	int			SetCameraScreenCenter( float x, float y ) ;																			// 画面上におけるカメラが見ている映像の中心の座標を設定する

extern	int			SetupCamera_Perspective( float Fov ) ;																				// 遠近?カメラをセットアップする
extern	int			SetupCamera_Ortho( float Size ) ;																					// 正射影カメラをセットアップする
extern	int			SetupCamera_ProjectionMatrix( MATRIX ProjectionMatrix ) ;															// 射影行列を設定する
extern	int			SetCameraDotAspect( float DotAspect ) ;																				// カメラのドットアスペクト比を設定する

extern	float		GetCameraNear( void ) ;																								// カメラの Near クリップ面の距離を取得する
extern	float		GetCameraFar( void ) ;																								// カメラの Far クリップ面の距離を取得する

extern	VECTOR		GetCameraPosition( void ) ;																							// カメラの位置を取得する
extern	VECTOR		GetCameraTarget( void ) ;																							// カメラの注視?を取得する
extern	VECTOR		GetCameraUpVector( void ) ;																							// カメラの視線に垂直な上方向のベクトルを得る
extern	float		GetCameraAngleHRotate( void ) ;																						// カメラの水平方向の向きを取得する
extern	float		GetCameraAngleVRotate( void ) ;																						// カメラの垂直方向の向きを取得する
extern	float		GetCameraAngleTRotate( void ) ;																						// カメラの向きの捻り角度を取得する

extern	MATRIX		GetCameraViewMatrix( void ) ;																						// ビュ?行列を取得する
extern	float		GetCameraFov( void ) ;																								// カメラの視野角を取得する
extern	float		GetCameraSize( void ) ;																								// カメラの視野サイズを取得する
extern	MATRIX		GetCameraProjectionMatrix( void ) ;																					// 射影行列を取得する
extern	float		GetCameraDotAspect( void ) ;																						// カメラのドットアスペクト比を得る

// ライト関係関数
extern	int			SetUseLighting( int Flag ) ;																						// ライティング計算??を使用するかどうかを設定する
extern	int			SetMaterialUseVertDifColor( int UseFlag ) ;																			// ３Ｄ???画のライティング計算に頂?カラ?のディフュ?ズカラ?を使用するかどうかを設定する
extern	int			SetMaterialUseVertSpcColor( int UseFlag ) ;																			// ３Ｄ???画のライティング計算に頂?カラ?のスペキュラカラ?を使用するかどうかを設定する
extern	int			SetMaterialParam( MATERIALPARAM Material ) ;																		// ３Ｄ???画のライティング計算に使用する?テリアルパラメ??を設定する
extern	int			SetUseSpecular( int UseFlag ) ;																						// ３Ｄ???画にスペキュラを使用するかどうかを設定する
extern	int			SetGlobalAmbientLight( COLOR_F Color ) ;																			// グロ?バルアンビエントライトカラ?を設定する

extern	int			ChangeLightTypeDir( VECTOR Direction ) ;																			// ライトの?イプをディレクショナルライトにする
extern	int			ChangeLightTypeSpot( VECTOR Position, VECTOR Direction, float OutAngle, float InAngle, float Range, float Atten0, float Atten1, float Atten2 ) ;	// ライトの?イプをス?ットライトにする
extern	int			ChangeLightTypePoint( VECTOR Position, float Range, float Atten0, float Atten1, float Atten2 ) ;					// ライトの?イプを?イントライトにする
extern	int			SetLightEnable( int EnableFlag ) ;																					// ライトの有効、無効をセットする
extern	int			SetLightDifColor( COLOR_F Color ) ;																					// ライトのディフュ?ズカラ?を設定する
extern	int			SetLightSpcColor( COLOR_F Color ) ;																					// ライトのスペキュラカラ?を設定する
extern	int			SetLightAmbColor( COLOR_F Color ) ;																					// ライトのアンビエントカラ?を設定する
extern	int			SetLightDirection( VECTOR Direction ) ;																				// ライトの方向を設定する
extern	int			SetLightPosition( VECTOR Position ) ;																				// ライトの位置を設定する
extern	int			SetLightRangeAtten( float Range, float Atten0, float Atten1, float Atten2 ) ;										// ライトの距離減衰パラメ??を設定する( 有効距離、距離減衰係数０、１、２ )
extern	int			SetLightAngle( float OutAngle, float InAngle ) ;																	// ライトのス?ットライトのパラメ??を設定する( 外部コ?ン角度、内部コ?ン角度 )
extern	int			GetLightType( void ) ;																								// ライトの?イプを取得する( 戻り値は DX_LIGHTTYPE_DIRECTIONAL 等 )
extern	int			GetLightEnable( void ) ;																							// ライト効果の有効、無効を取得する( TRUE:有効  FALSE:無効 )
extern	COLOR_F		GetLightDifColor( void ) ;																							// ライトのディフュ?ズカラ?を取得する
extern	COLOR_F		GetLightSpcColor( void ) ;																							// ライトのスペキュラカラ?を取得する
extern	COLOR_F		GetLightAmbColor( void ) ;																							// ライトのアンビエントカラ?を取得する
extern	VECTOR		GetLightDirection( void ) ;																							// ライトの方向を取得する
extern	VECTOR		GetLightPosition( void ) ;																							// ライトの位置を取得する
extern	int			GetLightRangeAtten( float *Range, float *Atten0, float *Atten1, float *Atten2 )	;									// ライトの距離減衰パラメ??を取得する( 有効距離、距離減衰係数０、１、２ )
extern	int			GetLightAngle( float *OutAngle, float *InAngle ) ;																	// ライトのス?ットライトのパラメ??を取得する( 外部コ?ン角度、内部コ?ン角度 )

extern	int			CreateDirLightHandle( VECTOR Direction ) ;																			// ディレクショナルライトハンドルを作成する
extern	int			CreateSpotLightHandle( VECTOR Position, VECTOR Direction, float OutAngle, float InAngle, float Range, float Atten0, float Atten1, float Atten2 ) ;	// ス?ットライトハンドルを作成する
extern	int			CreatePointLightHandle( VECTOR Position, float Range, float Atten0, float Atten1, float Atten2 ) ;					// ?イントライトハンドルを作成する
extern	int			DeleteLightHandle( int LHandle ) ;																					// ライトハンドルを削除する
extern	int			DeleteLightHandleAll( void ) ;																						// ライトハンドルを全て削除する
extern	int			SetLightTypeHandle( int LHandle, int LightType ) ;																	// ライトハンドルのライトの?イプを変更する( DX_LIGHTTYPE_DIRECTIONAL 等 )
extern	int			SetLightEnableHandle( int LHandle, int EnableFlag ) ;																// ライトハンドルのライト効果の有効、無効を設定する( TRUE:有効  FALSE:無効 )
extern	int			SetLightDifColorHandle( int LHandle, COLOR_F Color ) ;																// ライトハンドルのライトのディフュ?ズカラ?を設定する
extern	int			SetLightSpcColorHandle( int LHandle, COLOR_F Color ) ;																// ライトハンドルのライトのスペキュラカラ?を設定する
extern	int			SetLightAmbColorHandle( int LHandle, COLOR_F Color ) ;																// ライトハンドルのライトのアンビエントカラ?を設定する
extern	int			SetLightDirectionHandle( int LHandle, VECTOR Direction ) ;															// ライトハンドルのライトの方向を設定する
extern	int			SetLightPositionHandle( int LHandle, VECTOR Position ) ;															// ライトハンドルのライトの位置を設定する
extern	int			SetLightRangeAttenHandle( int LHandle, float Range, float Atten0, float Atten1, float Atten2 ) ;					// ライトハンドルのライトの距離減衰パラメ??を設定する( 有効距離、距離減衰係数０、１、２ )
extern	int			SetLightAngleHandle( int LHandle, float OutAngle, float InAngle ) ;													// ライトハンドルのライトのス?ットライトのパラメ??を設定する( 外部コ?ン角度、内部コ?ン角度 )
extern	int			GetLightTypeHandle( int LHandle ) ;																					// ライトハンドルのライトの?イプを取得する( 戻り値は DX_LIGHTTYPE_DIRECTIONAL 等 )
extern	int			GetLightEnableHandle( int LHandle ) ;																				// ライトハンドルのライト効果の有効、無効を取得する( TRUE:有効  FALSE:無効 )
extern	COLOR_F		GetLightDifColorHandle( int LHandle ) ;																				// ライトハンドルのライトのディフュ?ズカラ?を取得する
extern	COLOR_F		GetLightSpcColorHandle( int LHandle ) ;																				// ライトハンドルのライトのスペキュラカラ?を取得する
extern	COLOR_F		GetLightAmbColorHandle( int LHandle ) ;																				// ライトハンドルのライトのアンビエントカラ?を取得する
extern	VECTOR		GetLightDirectionHandle( int LHandle ) ;																			// ライトハンドルのライトの方向を取得する
extern	VECTOR		GetLightPositionHandle( int LHandle ) ;																				// ライトハンドルのライトの位置を取得する
extern	int			GetLightRangeAttenHandle( int LHandle, float *Range, float *Atten0, float *Atten1, float *Atten2 ) ;				// ライトハンドルのライトの距離減衰パラメ??を取得する( 有効距離、距離減衰係数０、１、２ )
extern	int			GetLightAngleHandle( int LHandle, float *OutAngle, float *InAngle ) ;												// ライトハンドルのライトのス?ットライトのパラメ??を取得する( 外部コ?ン角度、内部コ?ン角度 )

// グラフィック関係設定関数
extern	int			SetGraphColorBitDepth( int ColorBitDepth ) ;						// SetCreateGraphColorBitDepth の旧名称
extern	int			SetCreateGraphColorBitDepth( int BitDepth ) ;						// 作成するグラフィックの色?度を設定する
extern	int			GetCreateGraphColorBitDepth( void ) ;								// 作成するグラフィックの色?度を設定する
extern 	int			GetGraphColorBitDepth( void ) ;										// GetCreateGraphColorBitDepth の旧名称
extern	int			SetDrawValidGraphCreateFlag( int Flag ) ;							// ?画可?なグラフィックを作成するかどうかのフラグをセットする( TRUE:?画可?  FALSE:?画不可? )
extern	int			GetDrawValidGraphCreateFlag( void ) ;								// ?画可?なグラフィックを作成するかどうかのフラグを取得する
extern	int			SetLeftUpColorIsTransColorFlag( int Flag ) ;						// 画像左上の色を透過色にするかどうかのフラグをセットする
extern	int			GetUseBlendGraphCreateFlag( void ) ;								// ブレンド処理用画像を作成するかどうかのフラグを取得する
extern	int			GetUseSystemMemGraphCreateFlag( void ) ;							// システ?メモリ上にグラフィックを作成するかどうかのフラグを取得する( TRUE:システ?メモリ上に作成  FALSE:ＶＲ?Ｍ上に作成 )
extern	int			SetUseBlendGraphCreateFlag( int Flag ) ;							// ブレンド処理用画像を作成するかどうかのフラグをセットする
extern	int			SetUseAlphaTestGraphCreateFlag( int Flag ) ;						// アルフ?テストを使用するグラフィックを作成するかどうかのフラグをセットする
extern	int			SetUseAlphaTestFlag( int Flag ) ;									// SetUseAlphaTestGraphCreateFlag の旧名称
extern	int			SetUseNoBlendModeParam( int Flag ) ;								// SetDrawBlendMode 関数の第一引数に DX_BLENDMODE_NOBLEND を代入した際に、デフォルトでは第二引数は内部で２５５を指定したことになるが、その自動２５５化をしないかどうかを設定する( TRUE:しない(第二引数の値が使用される)   FALSE:する(第二引数の値は無視されて 255 が常に使用される)(デフォルト) )α?ャンネル付き画像に対して?画を行う場合のみ意味がある関数
extern	int			SetDrawValidFlagOf3DGraph( int Flag ) ;								// SetDrawValidGraphCreateFlag の旧名称
extern	int			GetUseAlphaTestFlag( void ) ;										// GetUseAlphaTestGraphCreateFlag の旧名称
extern	int			GetUseAlphaTestGraphCreateFlag( void ) ;							// アルフ?テストを使用するグラフィックを作成するかどうかのフラグを取得する
extern	int			SetDrawValidAlphaChannelGraphCreateFlag( int Flag ) ;				// ?画可?なα?ャンネル付き画像を作成するかどうかのフラグをセットする,SetDrawValidGraphCreateFlag 関数で?画可?画像を作成するように設定されていないと効果がない( TRUE:α?ャンネル付き FALSE:α?ャンネルなし )
extern	int			SetUseZBufferFlag( int Flag ) ;										// Ｚバッフ?を有効にするか、フラグをセットする( ２Ｄと３Ｄ?画に影響 )
extern	int			SetWriteZBufferFlag( int Flag ) ;									// Ｚバッフ?に書き込みを行うか、フラグをセットする( ２Ｄと３Ｄ?画に影響 )
extern	int			SetZBufferCmpType( int CmpType /* DX_CMP_NEVER 等 */ ) ;			// Ｚ値の比較モ?ドをセットする( ２Ｄと３Ｄ?画に影響 )
extern	int			SetZBias( int Bias ) ;												// Ｚバイアスをセットする( ２Ｄと３Ｄ?画に影響 )
extern	int			SetUseZBuffer3D( int Flag ) ;										// Ｚバッフ?を有効にするか、フラグをセットする( ３Ｄ???画のみに影響 )
extern	int			SetWriteZBuffer3D( int Flag ) ;										// Ｚバッフ?に書き込みを行うか、フラグをセットする( ３Ｄ???画のみに影響 )
extern	int			SetZBufferCmpType3D( int CmpType /* DX_CMP_NEVER 等 */ ) ;			// Ｚ値の比較モ?ドをセットする( ３Ｄ???画のみに影響 )
extern	int			SetZBias3D( int Bias ) ;											// Ｚバイアスをセットする( ３Ｄ???画のみに影響 )
extern	int			SetDrawZ( float Z ) ;												// ２Ｄ?画時にＺバッフ?に書き込むＺ値を変更する
extern	int			SetUseTransColor( int Flag ) ;										// 透過色??を使用するかどうかを設定する
extern	int			SetUseTransColorGraphCreateFlag( int Flag ) ;						// 透過色??を使用することを前提とした画像の読み込み処理を行うかどうかを設定する( TRUE にすると SetDrawMode( DX_DRAWMODE_BILINEAR ); をした状態で DrawGraphF 等の浮動小数??座標を受け取る関数で小数?以下の値を指定した場合に発生する?画結果の不自然を緩和する効果がある ( デフォルトは FALSE ) )
extern 	int			SetUseAlphaChannelGraphCreateFlag( int Flag ) ;						// α?ャンネル付きグラフィックを作成するかどうかのフラグをセットする( TRUE:α?ャンネル付き   FALSE:α?ャンネル無し )
extern 	int			SetUseGraphAlphaChannel( int Flag ) ;								// SetUseAlphaChannelGraphCreateFlag の旧名称
extern 	int			GetUseAlphaChannelGraphCreateFlag( void ) ;							// α?ャンネル付きグラフィックを作成するかどうかのフラグを取得する( TRUE:α?ャンネル付き   FALSE:α?ャンネル無し )
extern 	int			GetUseGraphAlphaChannel( void ) ;									// GetUseAlphaChannelGraphCreateFlag の旧名称
extern	int			SetUseNotManageTextureFlag( int Flag ) ;							// 非管理テクス?ャを使用するか、のフラグをセット( TRUE:使用する  FALSE:使用しない )
extern	int			SetTransColor( int Red, int Green, int Blue ) ;						// グラフィックに設定する透過色をセットする
extern	int			GetTransColor( int *Red, int *Green, int *Blue ) ;					// 透過色を得る
extern	int			GetDrawArea( RECT *Rect ) ;											// ?画可?領域を得る
extern	int			GetUseNotManageTextureFlag( void ) ;								// 非管理テクス?ャを使用するか、のフラグを取得する( TRUE:使用する  FALSE:使用しない )
extern	int			SetUseBasicGraphDraw3DDeviceMethodFlag( int Flag ) ;				// 単純??の?画に３Ｄデバイスの??を使用するかどうかのフラグをセットする
extern	int			SetWindowDrawRect( RECT *DrawRect ) ;								// 通常使用しない
extern	int			GetDrawBlendMode( int *BlendMode, int *BlendParam ) ;				// ?画ブレンドモ?ドを取得する
extern	int			GetDrawMode( void ) ;												// ?画モ?ドを取得する
extern	int			GetDrawBright( int *Red, int *Green, int *Blue ) ;					// ?画輝度を取得する
extern	int			GetActiveGraph( void ) ;											// アクティブになっているグラフィックのハンドルを得る
extern	int			GetTexFormatIndex( IMAGEFORMATDESC *Format ) ;						// テクス?ャフォ??ットのインデックスを得る
extern	int			SetWaitVSyncFlag( int Flag ) ;										// ＶＳＹＮＣ待ちをするかのフラグセット
extern	int			GetWaitVSyncFlag( void ) ;											// ＶＳＹＮＣ待ちをする設定になっているかどうかを取得する
extern	int			ColorKaiseki( void *PixelData, COLORDATA* ColorData ) ;				// 色ビット情報解析
extern	int			SetDefTransformMatrix( void ) ;										// デフォルトの変換行列をセットする
extern	int			CreatePixelFormat( D_DDPIXELFORMAT *PixelFormatBuf, int ColorBitDepth,
										 DWORD RedMask, DWORD GreenMask, DWORD BlueMask, DWORD AlphaMask ) ;		// DDPIXELFORMATデ??を作成する
extern	int			SetEmulation320x240( int Flag ) ;									// ６４０ｘ４８０の画面で３２０ｘ２４０の画面解像度にするかどうかのフラグをセットする、６４０ｘ４８０以外の解像度では無効( TRUE:有効  FALSE:無効 )








// DxMask.cpp 関数プロト?イプ宣言

#ifndef DX_NON_MASK

// ?スク関係 
extern	int			CreateMaskScreen( void ) ;																				// ?スクスクリ?ンを作成する
extern	int			DeleteMaskScreen( void ) ;																				// ?スクスクリ?ンを削除する
extern	void*		GetMaskSurface( void ) ; /* 戻り値を IDirectDrawSurface7 * にキャストして下さい */						// ?スクサ?フェスを取得する
//extern	MEMIMG*	GetMaskMemImg( void ) ;																				// ?スクサ?フェスの代わりの MEMIMG を取得する
extern	int			DrawMaskToDirectData( int x, int y, int Width, int Height, void *MaskData , int TransMode ) ;			// ?スクのデ??を直接セット
extern	int			DrawFillMaskToDirectData( int x1, int y1, int x2, int y2,  int Width, int Height, void *MaskData ) ;	// ?スクのデ??を直接?スク画面全体に?画する

extern	int			SetUseMaskScreenFlag( int ValidFlag ) ;																	// ?スク使用モ?ドを変更
extern	int			GetUseMaskScreenFlag( void ) ;																			// ?スク使用モ?ドの取得
extern	int			FillMaskScreen( int Flag ) ;																			// ?スクスクリ?ンを指定の色で塗りつぶす

extern	int			InitMask( void ) ;																						// ?スクデ??を初期化する
extern	int			MakeMask( int Width, int Height ) ;																		// ?スクデ??の追加
extern	int			GetMaskSize( int *WidthBuf, int *HeightBuf, int MaskHandle ) ;											// ?スクの大きさを得る 
extern	int			SetDataToMask( int Width, int Height, void *MaskData, int MaskHandle ) ;								// ?スクのデ??を?スクに?送する
extern	int			DeleteMask( int MaskHandle ) ;																			// ?スクデ??を削除
extern	int			BmpBltToMask( HBITMAP Bmp, int BmpPointX, int BmpPointY, int MaskHandle ) ;								// ?スクデ??にＢＭＰデ??を?スクデ??と見たてて?送
extern	int			LoadMask( const TCHAR *FileName ) ;																		// ?スクデ??をロ?ドする
extern	int			LoadDivMask( const TCHAR *FileName, int AllNum, int XNum, int YNum, int XSize, int YSize, int *HandleBuf ) ;	// ?スクを画像から分割読みこみ
extern	int			DrawMask( int x, int y, int MaskHandle, int TransMode ) ;												// ?スクをセットする
extern	int			DrawFormatStringMask( int x, int y, int Flag, const TCHAR *FormatString, ... ) ;							// 書式指定ありの文字列を?スクスクリ?ンに?画する
extern	int			DrawFormatStringMaskToHandle( int x, int y, int Flag, int FontHandle, const TCHAR *FormatString, ... ) ;	// 書式指定ありの文字列を?スクスクリ?ンに?画する(フォントハンドル指定版)( SetFontCacheToTextureFlag( FALSE ) ; にして作成したフォントハンドルのみ使用可? )
extern	int			DrawStringMask( int x, int y, int Flag, const TCHAR *String ) ;											// 文字列を?スクスクリ?ンに?画する
extern	int			DrawStringMaskToHandle( int x, int y, int Flag, int FontHandle, const TCHAR *String ) ;					// 文字列を?スクスクリ?ンに?画する(フォントハンドル指定版)( SetFontCacheToTextureFlag( FALSE ) ; にして作成したフォントハンドルのみ使用可? )
extern	int			DrawFillMask( int x1, int y1, int x2, int y2, int MaskHandle ) ;										// 指定の?スクを画面いっぱいに展開する	
extern	int			SetMaskTransColor( int ColorCode ) ;																	// ( Ver3.0 以?では無効 ) ?スクに使う透過色のセット
extern	int			SetMaskReverseEffectFlag( int ReverseFlag ) ;															// ?スクの数値に対する効果を逆?させる

extern 	int			GetMaskScreenData( int x1, int y1, int x2, int y2, int MaskHandle ) ;									// ?スク画面上の?画状態を取得する
extern	int			GetMaskUseFlag( void ) ;																				// ?スクスクリ?ンを使用中かフラグの取得

#endif










// DxMovie.cpp 関数プロト?イプ宣言
extern	int			SetMovieRightImageAlphaFlag( int Flag ) ;							// 動画フ?イルの右半分をアルフ?情報として扱うかどうかをセットする( TRUE:アルフ?情報として扱う )













// DxFont.cpp 関数プロト?イプ宣言

// フォント、文字列?画関係関数
extern	int			EnumFontName( TCHAR *NameBuffer, int NameBufferNum, int JapanOnlyFlag = TRUE ) ;								// 使用可?なフォントの名前をすべて列挙する( NameBuffer に 64バイト区切りで名前が格?されます )
extern	int			EnumFontNameEx( TCHAR *NameBuffer, int NameBufferNum, int CharSet = -1 /* DX_CHARSET_DEFAULT 等 */ ) ;		// 使用可?なフォントの名前をすべて列挙する( NameBuffer に 64バイト区切りで名前が格?されます )
extern	int			InitFontToHandle( void ) ;																					// フォントのステ??スをデフォルトに戻す
extern	int			CreateFontToHandle( const TCHAR *FontName, int Size, int Thick, int FontType = -1 , int CharSet = -1 , int EdgeSize = -1 , int Italic = FALSE , int DataIndex = -1 , int ID = -1 ) ;			// 新しいフォントデ??を作成
extern	int			SetFontSpaceToHandle( int Point, int FontHandle ) ;															// 字間を変更する
extern	int			SetDefaultFontState( const TCHAR *FontName, int Size, int Thick ) ;											// デフォルトフォントのステ??スを一括設定する
extern	int			DeleteFontToHandle( int FontHandle ) ;																		// フォントキャッシュの制御を終了する
extern	int			SetFontLostFlag( int FontHandle, int *LostFlag ) ;															// 解放時に TRUE にするフラグへの?イン?を設定する
extern	int			SetFontSize( int FontSize ) ;																				// ?画するフォントのサイズをセットする
extern	int			SetFontThickness( int ThickPal ) ;																			// フォントの太さをセット
extern	int			SetFontSpace( int Point ) ;																					// 字間を変更する
extern	int			SetFontCacheToTextureFlag( int Flag ) ;																		// フォントのキャッシュにテクス?ャを使用するか、フラグをセットする
extern	int			SetFontChacheToTextureFlag( int Flag ) ;																	// フォントのキャッシュにテクス?ャを使用するか、フラグをセットする(誤字版)
extern	int			SetFontCacheCharNum( int CharNum ) ;																		// フォントキャッシュでキャッシュできる文字数を指定する
extern	int			ChangeFont( const TCHAR *FontName, int CharSet = -1 /* DX_CHARSET_SHFTJIS 等 */ ) ;							// フォントを変更
extern	int			ChangeFontType( int FontType ) ;																			// フォント?イプの変更
// FontCacheStringDraw は DrawString を使ってください
extern	int			FontCacheStringDrawToHandle( int x, int y, const TCHAR *StrData, int Color, int EdgeColor,
													BASEIMAGE *DestImage, RECT *ClipRect /* NULL 可 */ , int FontHandle,
													int VerticalFlag = FALSE , SIZE *DrawSizeP = NULL ) ;
extern	int			FontBaseImageBlt( 
						int x, int y, const TCHAR *StrData,
						BASEIMAGE *DestImage, BASEIMAGE *DestEdgeImage,
						int VerticalFlag = FALSE ) ;																			// 基?イメ?ジに文字列イメ?ジを?送する
extern	int			FontBaseImageBltToHandle( 
						int x, int y, const TCHAR *StrData,
						BASEIMAGE *DestImage, BASEIMAGE *DestEdgeImage,
						int FontHandle, int VerticalFlag = FALSE ) ;															// 基?イメ?ジに文字列イメ?ジを?送する

extern	int			GetFontMaxWidth( void ) ;																					// 文字の最大幅を得る
extern	int			GetFontMaxWidthToHandle( int FontHandle ) ;																	// 文字の最大幅を得る
extern	int			GetFontCharInfo( int FontHandle, const TCHAR *Char, int *DrawX, int *DrawY, int *NextCharX, int *SizeX, int *SizeY ) ;		// 指定の文字の?画情報を取得する
extern	int			GetDrawStringWidth( const TCHAR *String, int StrLen, int VerticalFlag = FALSE ) ;							// 文字列の幅を得る
extern	int			GetDrawFormatStringWidth( const TCHAR *FormatString, ... ) ;													// 書式付き文字列の?画幅を得る
extern	int			GetDrawStringWidthToHandle( const TCHAR *String, int StrLen, int FontHandle, int VerticalFlag = FALSE ) ;	// 文字列の幅を得る
extern	int			GetDrawFormatStringWidthToHandle( int FontHandle, const TCHAR *FormatString, ... ) ;							// 書式付き文字列の?画幅を得る
extern	int			GetDrawExtendStringWidth( double ExRateX, const TCHAR *String, int StrLen, int VerticalFlag = FALSE ) ;							// 文字列の幅を得る
extern	int			GetDrawExtendFormatStringWidth( double ExRateX, const TCHAR *FormatString, ... ) ;												// 書式付き文字列の?画幅を得る
extern	int			GetDrawExtendStringWidthToHandle( double ExRateX, const TCHAR *String, int StrLen, int FontHandle, int VerticalFlag = FALSE ) ;	// 文字列の幅を得る
extern	int			GetDrawExtendFormatStringWidthToHandle( double ExRateX, int FontHandle, const TCHAR *FormatString, ... ) ;						// 書式付き文字列の?画幅を得る
extern	int			GetFontStateToHandle( TCHAR *FontName, int *Size, int *Thick, int FontHandle) ;								// フォントの情報を得る
extern	int			GetDefaultFontHandle( void ) ;																				// デフォルトのフォントのハンドルを得る
extern	int			GetFontChacheToTextureFlag( void ) ;																		// フォントにテクス?ャキャッシュを使用するかどうかを取得する(誤字版)
extern	int			GetFontCacheToTextureFlag( void ) ;																			// フォントにテクス?ャキャッシュを使用するかどうかを取得する
extern	int			CheckFontChacheToTextureFlag( int FontHandle ) ;															// 指定のフォントがテクス?ャキャッシュを使用しているかどうかを得る(誤字版)
extern	int			CheckFontCacheToTextureFlag( int FontHandle ) ;																// 指定のフォントがテクス?ャキャッシュを使用しているかどうかを得る
//extern	LPFONTMANAGE GetFontManageDataToHandle( int FontHandle ) ;																// フォント管理デ??の取得
extern	int			CheckFontHandleValid( int FontHandle ) ;																	// 指定のフォントハンドルが有効か否か調べる
extern	int			MultiByteCharCheck( const char *Buf, int CharSet /* DX_CHARSET_SHFTJIS */ ) ;									// ２バイト文字か調べる( TRUE:２バイト文字  FALSE:１バイト文字 )
extern	int			GetFontCacheCharNum( void ) ;																				// フォントキャッシュでキャッシュできる文字数を取得する( 戻り値  0:デフォルト  1以上:指定文字数 )
extern	int			GetFontSize( void ) ;																						// フォントのサイズを得る
extern	int			GetFontSizeToHandle( int FontHandle ) ;																		// フォントのサイズを得る









// DxMath.cpp 関数プロト?イプ宣言

// 演算ライブラリ
extern	int			CreateIdentityMatrix( MATRIX *Out ) ;														// 単位行列を作成する
extern	int			CreateLookAtMatrix( MATRIX *Out, VECTOR *Eye, VECTOR *At, VECTOR *Up ) ;					// ビュ?行列を作成する
extern	int			CreateLookAtMatrix2( MATRIX *Out, VECTOR *Eye, double XZAngle, double Oira ) ;				// ビュ?行列を作成する
extern	int			CreateLookAtMatrixRH( MATRIX *Out, VECTOR *Eye, VECTOR *At, VECTOR *Up ) ;					// ビュ?行列を作成する(右手座標系用)
extern	int			CreateMultiplyMatrix( MATRIX *Out, MATRIX *In1, MATRIX *In2 ) ;								// 行列の積を求める
extern	int			CreatePerspectiveFovMatrix( MATRIX *Out, float fov, float zn, float zf, float aspect = -1.0f ) ;	// 射影行列を作成する
extern	int			CreatePerspectiveFovMatrixRH( MATRIX *Out, float fov, float zn, float zf, float aspect = -1.0f ) ;	// 射影行列を作成する(右手座標系用)
extern	int			CreateOrthoMatrix( MATRIX *Out, float size, float zn, float zf, float aspect = -1.0f ) ;	// 正射影行列を作成する
extern	int			CreateOrthoMatrixRH( MATRIX *Out, float size, float zn, float zf, float aspect = -1.0f ) ;	// 正射影行列を作成する(右手座標系用)
extern	int			CreateScalingMatrix( MATRIX *Out, float sx, float sy, float sz ) ;							// スケ?リング行列を作成する
extern	int			CreateRotationXMatrix( MATRIX *Out, float Angle ) ;											// Ｘ軸を中心とした回?行列を作成する
extern	int			CreateRotationYMatrix( MATRIX *Out, float Angle ) ;											// Ｙ軸を中心とした回?行列を作成する
extern	int			CreateRotationZMatrix( MATRIX *Out, float Angle ) ;											// Ｚ軸を中心とした回?行列を作成する
extern	int			CreateTranslationMatrix( MATRIX *Out, float x, float y, float z ) ;							// 平行移動行列を作成する
extern	int			CreateTransposeMatrix( MATRIX *Out, MATRIX *In ) ;											// ?置行列を作成する
extern	int			CreateInverseMatrix( MATRIX *Out, MATRIX *In ) ;											// 逆行列を作成する
extern	int			CreateViewportMatrix( MATRIX *Out, float CenterX, float CenterY, float Width, float Height ) ; // ビュ???ト行列を作成する
extern	int			CreateRotationXYZMatrix( MATRIX *Out, float XRot, float YRot, float ZRot ) ;				// Ｘ軸回?→Ｙ軸回?→Ｚ軸回?を合成した行列を作成する
extern	int			CreateRotationXZYMatrix( MATRIX *Out, float XRot, float YRot, float ZRot ) ;				// Ｘ軸回?→Ｚ軸回?→Ｙ軸回?を合成した行列を作成する
extern	int			CreateRotationYXZMatrix( MATRIX *Out, float XRot, float YRot, float ZRot ) ;				// Ｙ軸回?→Ｘ軸回?→Ｚ軸回?を合成した行列を作成する
extern	int			CreateRotationYZXMatrix( MATRIX *Out, float XRot, float YRot, float ZRot ) ;				// Ｙ軸回?→Ｚ軸回?→Ｘ軸回?を合成した行列を作成する
extern	int			CreateRotationZXYMatrix( MATRIX *Out, float XRot, float YRot, float ZRot ) ;				// Ｚ軸回?→Ｘ軸回?→Ｙ軸回?を合成した行列を作成する
extern	int			CreateRotationZYXMatrix( MATRIX *Out, float XRot, float YRot, float ZRot ) ;				// Ｚ軸回?→Ｙ軸回?→Ｘ軸回?を合成した行列を作成する
extern	int			GetMatrixXYZRotation( MATRIX *In, float *OutXRot, float *OutYRot, float *OutZRot ) ;		// 行列からＸＹＺ軸回?の値を取得する( 戻り値?-1:ジンバルロック発生  0:成功 )
extern	int			GetMatrixXZYRotation( MATRIX *In, float *OutXRot, float *OutYRot, float *OutZRot ) ;		// 行列からＸＺＹ軸回?の値を取得する( 戻り値?-1:ジンバルロック発生  0:成功 )
extern	int			GetMatrixYXZRotation( MATRIX *In, float *OutXRot, float *OutYRot, float *OutZRot ) ;		// 行列からＹＸＺ軸回?の値を取得する( 戻り値?-1:ジンバルロック発生  0:成功 )
extern	int			GetMatrixYZXRotation( MATRIX *In, float *OutXRot, float *OutYRot, float *OutZRot ) ;		// 行列からＹＺＸ軸回?の値を取得する( 戻り値?-1:ジンバルロック発生  0:成功 )
extern	int			GetMatrixZXYRotation( MATRIX *In, float *OutXRot, float *OutYRot, float *OutZRot ) ;		// 行列からＺＸＹ軸回?の値を取得する( 戻り値?-1:ジンバルロック発生  0:成功 )
extern	int			GetMatrixZYXRotation( MATRIX *In, float *OutXRot, float *OutYRot, float *OutZRot ) ;		// 行列からＺＹＸ軸回?の値を取得する( 戻り値?-1:ジンバルロック発生  0:成功 )
extern	int			VectorNormalize( VECTOR *Out, VECTOR *In ) ;												// ベクトルを正規化する
extern	int			VectorScale( VECTOR *Out, VECTOR *In, float Scale ) ;										// ベクトルをスカラ??する
extern	int			VectorMultiply( VECTOR *Out, VECTOR *In1, VECTOR *In2 ) ;									// ベクトルの?け算をする
extern	int			VectorSub( VECTOR *Out, VECTOR *In1, VECTOR *In2 ) ;										// Out = In1 - In2 のベクトル計算をする 
extern	int			VectorAdd( VECTOR *Out, VECTOR *In1, VECTOR *In2 ) ;										// Out = In1 + In2 のベクトル計算をする 
extern	int			VectorOuterProduct( VECTOR *Out, VECTOR *In1, VECTOR *In2 ) ;								// In1とIn2の外積を計算する
extern	float		VectorInnerProduct( VECTOR *In1, VECTOR *In2 ) ;											// In1とIn2の内積を計算する
extern	int			VectorRotationX( VECTOR *Out, VECTOR *In, double Angle ) ;									// ベクトルのＸ軸を軸にした回?を行う
extern	int			VectorRotationY( VECTOR *Out, VECTOR *In, double Angle ) ;									// ベクトルのＹ軸を軸にした回?を行う
extern	int			VectorRotationZ( VECTOR *Out, VECTOR *In, double Angle ) ;									// ベクトルのＺ軸を軸にした回?を行う
extern	int			VectorTransform( VECTOR *Out, VECTOR *InVec, MATRIX *InMatrix ) ;							// ベクトル行列と4x4正方行列を乗算する( w は 1 と仮定 )
extern	int			VectorTransform4( VECTOR *Out, float *V4Out, VECTOR *InVec, float *V4In, MATRIX *InMatrix ) ; // ベクトル行列と4x4正方行列を乗算する( w の要素を渡す )

extern	void		TriangleBarycenter( VECTOR TrianglePos1, VECTOR TrianglePos2, VECTOR TrianglePos3, VECTOR Position, float *u, float *v, float *w ) ;	// 指定の座標から三角?の重心を求める

extern	float		Segment_Segment_MinLength( VECTOR SegmentAPos1, VECTOR SegmentAPos2, VECTOR SegmentBPos1, VECTOR SegmentBPos2 ) ;								// 二つの線分の最近?間の距離を得る
extern	float		Segment_Segment_MinLength_Square( VECTOR SegmentAPos1, VECTOR SegmentAPos2, VECTOR SegmentBPos1, VECTOR SegmentBPos2 ) ;						// 二つの線分の最近?間の距離の二乗を得る
extern	float		Segment_Triangle_MinLength( VECTOR SegmentPos1, VECTOR SegmentPos2, VECTOR TrianglePos1, VECTOR TrianglePos2, VECTOR TrianglePos3 ) ;			// 線分と三角?の最近?間の距離を得る 
extern	float		Segment_Triangle_MinLength_Square( VECTOR SegmentPos1, VECTOR SegmentPos2, VECTOR TrianglePos1, VECTOR TrianglePos2, VECTOR TrianglePos3 ) ;	// 線分と三角?の最近?間の距離の二乗を得る 
extern	float		Segment_Point_MinLength( VECTOR SegmentPos1, VECTOR SegmentPos2, VECTOR PointPos ) ;															// 線分と?の一番近い距離を得る
extern	float		Segment_Point_MinLength_Square( VECTOR SegmentPos1, VECTOR SegmentPos2, VECTOR PointPos ) ;														// 線分と?の一番近い距離の二乗を得る
extern	float		Triangle_Point_MinLength( VECTOR TrianglePos1, VECTOR TrianglePos2, VECTOR TrianglePos3, VECTOR PointPos ) ;									// 三角?と?の一番近い距離を得る
extern	float		Triangle_Point_MinLength_Square( VECTOR TrianglePos1, VECTOR TrianglePos2, VECTOR TrianglePos3, VECTOR PointPos ) ;								// 三角?と?の一番近い距離の二乗を得る

extern	HITRESULT_LINE HitCheck_Line_Triangle( VECTOR LinePos1, VECTOR LinePos2, VECTOR TrianglePos1, VECTOR TrianglePos2, VECTOR TrianglePos3 ) ;					// 三角?と線の当たり判定
extern	int			HitCheck_Triangle_Triangle( VECTOR Triangle1Pos1, VECTOR Triangle1Pos2, VECTOR Triangle1Pos3, 
											    VECTOR Triangle2Pos1, VECTOR Triangle2Pos2, VECTOR Triangle2Pos3 ) ;												// 三角?と三角?の当たり判定( TRUE:当たっている  FALSE:当たっていない )
extern	int			HitCheck_Line_Sphere( VECTOR LinePos1, VECTOR LinePos2, VECTOR SphereCenterPos, float SphereR ) ;												// 線と球の当たり判定( TRUE:当たっている  FALSE:当たっていない )
extern	int			HitCheck_Sphere_Sphere( VECTOR Sphere1CenterPos, float Sphere1R, VECTOR Sphere2CenterPos, float Sphere2R ) ;									// 球と球の当たり判定( TRUE:当たっている  FALSE:当たっていない )
extern	int			HitCheck_Sphere_Triangle( VECTOR SphereCenterPos, float SphereR, VECTOR TrianglePos1, VECTOR TrianglePos2, VECTOR TrianglePos3 ) ;				// 球と三角?の当たり判定( TRUE:当たっている  FALSE:当たっていない )
extern	int			HitCheck_Capsule_Capsule( VECTOR Cap1Pos1, VECTOR Cap1Pos2, float Cap1R, VECTOR Cap2Pos1, VECTOR Cap2Pos2, float Cap2R ) ;						// カプセル同士の当たり判定( TRUE:当たっている  FALSE:当たっていない )
extern	int			HitCheck_Capsule_Triangle( VECTOR CapPos1, VECTOR CapPos2, float CapR, VECTOR TrianglePos1, VECTOR TrianglePos2, VECTOR TrianglePos3 ) ;		// カプセルと三角?の当たり判定( TRUE:当たっている  FALSE:当たっていない )

// その他
extern	int			RectClipping( RECT *MotoRect, RECT *ClippuRect ) ;											// 矩?のクリッピング
extern	int			RectAdjust( RECT *Rect ) ;																	// 矩?の left が right より値が大きい場合などの誤りを補正する
extern	int			GetRectSize( RECT *Rect, int *Width, int *Height ) ;										// 矩?の幅と高さを求める

// ?記簡略版
extern	MATRIX		MGetIdent( void ) ;														// 単位行列を得る
extern	MATRIX		MMult( MATRIX In1, MATRIX In2 ) ;										// 行列の乗算を行う
extern	MATRIX		MScale( MATRIX InM, float Scale ) ;										// 行列のスケ?リングを行う
extern	MATRIX		MAdd( MATRIX In1, MATRIX In2 ) ;										// 行列の足し算を行う
extern	MATRIX		MGetScale( VECTOR Scale ) ;												// 拡大行列を得る
extern	MATRIX		MGetRotX( float XAxisRotate ) ;											// Ｘ軸回?行列を得る
extern	MATRIX		MGetRotY( float YAxisRotate ) ;											// Ｙ軸回?行列を得る
extern	MATRIX		MGetRotZ( float ZAxisRotate ) ;											// Ｚ軸回?行列を得る
extern	MATRIX		MGetRotAxis( VECTOR RotateAxis, float Rotate ) ;						// 指定軸で指定角度回?する行列を得る
extern	MATRIX		MGetRotVec2( VECTOR In1, VECTOR In2 ) ;									// In1 の向きから In2 の向きへ変換する回?行列を得る( In2 と In1 が?逆のベクトルの場合は回?軸は不定 )
extern	MATRIX		MGetTranslate( VECTOR Trans ) ;											// 平行移動行列を得る
extern	MATRIX		MGetAxis1( VECTOR XAxis, VECTOR YAxis, VECTOR ZAxis, VECTOR Pos ) ;		// 指定の３軸ロ?カルのベクトルを基?軸上のベクトルに変換する行列を得る( x' = XAxis.x * x + YAixs.x * y + ZAxis.z * z + Pos.x   y' = XAxis.y * x + YAixs.y * y + ZAxis.y * z + Pos.y      z' = XAxis.z * x + YAixs.z * y + ZAxis.z * z + Pos.z )
extern	MATRIX		MGetAxis2( VECTOR XAxis, VECTOR YAxis, VECTOR ZAxis, VECTOR Pos ) ;		// 基?軸上のベクトルを指定の３軸上に投影したベクトルに変換する行列を得る( x' = XAxis.x * ( x - Pos.x ) + XAxis.y * ( x - Pos.x ) + XAxis.z * ( x - Pos.x )    y' = YAxis.x * ( x - Pos.x ) + YAxis.y * ( x - Pos.x ) + YAxis.z * ( x - Pos.x )    z' = ZAxis.x * ( x - Pos.x ) + ZAxis.y * ( x - Pos.x ) + ZAxis.z * ( x - Pos.x ) )
extern	MATRIX		MTranspose( MATRIX InM ) ;												// ?置行列を得る
extern	MATRIX		MInverse( MATRIX InM ) ;												// 逆行列を得る
extern  VECTOR		MGetSize( MATRIX InM ) ;												// 拡大行列のＸ軸、Ｙ軸、Ｚ軸の拡大率を得る

// ベクトル値の生成
__inline VECTOR VGet( float x, float y, float z )
{
	VECTOR Result;
	Result.x = x ;
	Result.y = y ;
	Result.z = z ;
	return Result ;
}

// ベクトルの加算
__inline VECTOR		VAdd( const VECTOR &In1, const VECTOR &In2 )
{
	VECTOR Result ;
	Result.x = In1.x + In2.x ;
	Result.y = In1.y + In2.y ;
	Result.z = In1.z + In2.z ;
	return Result ;
}

// ベクトルの減算
__inline VECTOR		VSub( const VECTOR &In1, const VECTOR &In2 )
{
	VECTOR Result ;
	Result.x = In1.x - In2.x ;
	Result.y = In1.y - In2.y ;
	Result.z = In1.z - In2.z ;
	return Result ;
}

// ベクトルの内積
__inline float		VDot( const VECTOR &In1, const VECTOR &In2 )
{
	return In1.x * In2.x + In1.y * In2.y + In1.z * In2.z ;
}

// ベクトルの外積
__inline VECTOR		VCross( const VECTOR &In1, const VECTOR &In2 )
{
	VECTOR Result ;
	Result.x = In1.y * In2.z - In1.z * In2.y ;
	Result.y = In1.z * In2.x - In1.x * In2.z ;
	Result.z = In1.x * In2.y - In1.y * In2.x ;
	return Result ;
}

// ベクトルのスケ?リング
__inline VECTOR		VScale( const VECTOR &In, float Scale )
{
	VECTOR Result ;
	Result.x = In.x * Scale ;
	Result.y = In.y * Scale ;
	Result.z = In.z * Scale ;
	return Result ;
}

// ベクトルの正規化
extern VECTOR		VNorm( VECTOR In ) ;

// ベクトルのサイズ
extern float		VSize( VECTOR In ) ;

// ベクトルのサイズの２乗
__inline float		VSquareSize( const VECTOR &In )
{
	return In.x * In.x + In.y * In.y + In.z * In.z ;
}

// 行列を使った座標変換
__inline VECTOR		VTransform( const VECTOR &InV, const MATRIX &InM )
{
	VECTOR Result ;
	Result.x = InV.x * InM.m[0][0] + InV.y * InM.m[1][0] + InV.z * InM.m[2][0] + InM.m[3][0] ;
	Result.y = InV.x * InM.m[0][1] + InV.y * InM.m[1][1] + InV.z * InM.m[2][1] + InM.m[3][1] ;
	Result.z = InV.x * InM.m[0][2] + InV.y * InM.m[1][2] + InV.z * InM.m[2][2] + InM.m[3][2] ;
	return Result ;
}

// 行列を使った座標変換( スケ?リング?回?成分のみ )
__inline VECTOR		VTransformSR( const VECTOR &InV, const MATRIX &InM )
{
	VECTOR Result ;
	Result.x = InV.x * InM.m[0][0] + InV.y * InM.m[1][0] + InV.z * InM.m[2][0] ;
	Result.y = InV.x * InM.m[0][1] + InV.y * InM.m[1][1] + InV.z * InM.m[2][1] ;
	Result.z = InV.x * InM.m[0][2] + InV.y * InM.m[1][2] + InV.z * InM.m[2][2] ;
	return Result ;
}

// 二つのベクトルが成す角のコサイン値を得る
extern	float		VCos( VECTOR In1, VECTOR In2 ) ;

// 二つのベクトルが成す角の角度を得る( 単位：ラジアン )
extern	float		VRad( VECTOR In1, VECTOR In2 ) ;








// DxBaseImage.cpp 関数プロト?イプ宣言

// 基?イメ?ジデ??のロ?ド?ＤＩＢ関係
extern	int			CreateGraphImageOrDIBGraph( const TCHAR *FileName, void *DataImage, int DataImageSize, int DataImageType, int BmpFlag, int ReverseFlag, BASEIMAGE *Image, BITMAPINFO **BmpInfo, void **GraphData ) ;												// 登?されている各種グラフィックロ??関数から、ＢＭＰデ??もしくは GraphImageデ??を?築する
extern	int			CreateGraphImageType2( STREAMDATA *Src, BASEIMAGE *Dest ) ;																																														// 汎用読み込み処理によるグラフィックイメ?ジ?築関数( 0:成功  -1:失敗 )

extern	int			CreateBmpInfo( BITMAPINFO *BmpInfo, int Width, int Height, int Pitch, void *SrcGrData, void **DestGrData ) ;																																	// フルカラ??式のBITMAPINFO?造体を作成する
extern	HBITMAP		CreateDIBGraphVer2( const TCHAR *FileName, void *MemImage, int MemImageSize, int ImageType, int ReverseFlag, COLORDATA *SrcColor ) ;																												// ＤＩＢグラフィックを作成する(バ?ジョン２)
extern	int			CreateDIBGraphVer2_plus_Alpha( const TCHAR *FileName, void *MemImage, int MemImageSize, void *AlphaImage, int AlphaImageSize, int ImageType, HBITMAP *RGBBmp, HBITMAP *AlphaBmp, int ReverseFlag, COLORDATA *SrcColor ) ;						// ＤＩＢグラフィックを作成する
extern	DWORD		GetGraphImageFullColorCode( BASEIMAGE *GraphImage, int x, int y ) ;																																												// BASEIMAGE ?造体の画像情報から指定の座標のフルカラ?コ?ドを取得する
extern	int			CreateGraphImage_plus_Alpha( const TCHAR *FileName, void *RgbImage, int RgbImageSize, int RgbImageType,
													void *AlphaImage, int AlphaImageSize, int AlphaImageType,
													BASEIMAGE *RgbGraphImage, BASEIMAGE *AlphaGraphImage, int ReverseFlag ) ;																																	// 各種グラフィックデ??からグラフィックイメ?ジデ??とアルフ??ップ用イメ?ジデ??を?築する
extern	int			ReverseGraphImage( BASEIMAGE *GraphImage ) ;																																																	// 指定の GraphImage を左右反?する
extern	int			ConvBitmapToGraphImage( BITMAPINFO *BmpInfo, void *GraphData, BASEIMAGE *GraphImage, int CopyFlag ) ;																																			// ＢＭＰ を GraphImage に変換する( Ret 0:正常終了  1:コピ?を行った  -1:エラ? )
extern	int			ConvGraphImageToBitmap( BASEIMAGE *GraphImage, BITMAPINFO *BmpInfo, void **GraphData, int CopyFlag, int FullColorConv = TRUE ) ;																												// GraphImage を ＢＭＰ に変換する(アルフ?デ??はあっても無視される)( Ret 0:正常終了  1:コピ?を行った  -1:エラ? )
extern	HBITMAP		CreateDIBGraph( const TCHAR *FileName, int ReverseFlag, COLORDATA *SrcColor) ;																																									// ＤＩＢグラフィックを作成する
extern	HBITMAP		CreateDIBGraphToMem( BITMAPINFO *BmpInfo, void *GraphData, int ReverseFlag, COLORDATA *SrcColor ) ;																																				// ＤＩＢグラフィックをメモリイメ?ジから作成する
extern	int			CreateDIBGraph_plus_Alpha( const TCHAR *FileName, HBITMAP *RGBBmp, HBITMAP *AlphaBmp, int ReverseFlag = FALSE , COLORDATA *SrcColor = NULL ) ;																									// フ?イルからＤＩＢグラフィックと?スクグラフィックを作成する

//extern int		AddUserGraphLoadFunction( int ( *UserLoadFunc )( FILE *fp, BITMAPINFO **BmpInfo, void **GraphData ) ) ;																					// ユ?ザ?定?のグラフィックロ?ド関数を登?する
//extern int		AddUserGraphLoadFunction2( int ( *UserLoadFunc )( void *Image, int ImageSize, int ImageType, BITMAPINFO **BmpInfo, void **GraphData ) ) ;												// ユ?ザ?定?のグラフィックロ?ド関数を登?する
//extern int		AddUserGraphLoadFunction3( int ( *UserLoadFunc )( void *DataImage, int DataImageSize, int DataImageType, int BmpFlag, BASEIMAGE *Image, BITMAPINFO **BmpInfo, void **GraphData ) ) ;	// ユ?ザ?定?のグラフィックロ?ド関数Ver3を登?する
extern	int			AddUserGraphLoadFunction4( int (* UserLoadFunc )( STREAMDATA *Src, BASEIMAGE *Image ) ) ; 																								// ユ?ザ?定?のグラフィックロ?ド関数Ver4を登?する
//extern int		SubUserGraphLoadFunction( int ( *UserLoadFunc )( FILE *fp, BITMAPINFO **BmpInfo, void **GraphData ) ) ;																					// ユ?ザ?定?のグラフィックロ?ド関数を登?から抹消する
//extern int		SubUserGraphLoadFunction2( int ( *UserLoadFunc )( void *Image, int ImageSize, int ImageType, BITMAPINFO **BmpInfo, void **GraphData ) ) ;												// ユ?ザ?定?のグラフィックロ?ド関数を登?から抹消する
//extern int		SubUserGraphLoadFunction3( int ( *UserLoadFunc )( void *DataImage, int DataImageSize, int DataImageType, int BmpFlag, BASEIMAGE *Image, BITMAPINFO **BmpInfo, void **GraphData ) ) ;	// ユ?ザ?定?のグラフィックロ?ド関数Ver3を登?から抹消する
extern	int			SubUserGraphLoadFunction4( int (* UserLoadFunc )( STREAMDATA *Src, BASEIMAGE *Image ) ) ; 																								// ユ?ザ?定?のグラフィックロ?ド関数Ver4を登?から抹消する

extern	int			SetUseFastLoadFlag( int Flag ) ;																							// 高速読み込みル??ンを使うか否かのフラグをセットする
extern	int			GetGraphDataShavedMode( void ) ;																							// グラフィック減色時の画像劣化緩和処理モ?ドの取得
extern	int			SetGraphDataShavedMode( int ShavedMode ) ;																					// グラフィック減色時の画像劣化緩和処理モ?ドの変更

// 基?イメ?ジデ????公開用関数
extern	int			InitSoftImage( void ) ;																										// ?フトウエアで扱うイメ?ジを全て解放する
extern	int			LoadSoftImage( const TCHAR *FileName ) ;																						// ?フトウエアで扱うイメ?ジの読み込み( -1:エラ?  -1以外:イメ?ジハンドル )
extern	int			LoadSoftImageToMem( void *FileImage, int FileImageSize ) ;																	// ?フトウエアで扱うイメ?ジのメモリからの読み込み( -1:エラ?  -1以外:イメ?ジハンドル )
extern	int			MakeSoftImage( int SizeX, int SizeY ) ;																						// ?フトウエアで扱うイメ?ジの作成( -1:エラ?  -1以外:イメ?ジハンドル )
extern	int			MakeARGB8ColorSoftImage( int SizeX, int SizeY ) ;																			// ?フトウエアで扱うイメ?ジの作成( RGBA8 カラ? )
extern	int			MakeXRGB8ColorSoftImage( int SizeX, int SizeY ) ;																			// ?フトウエアで扱うイメ?ジの作成( XRGB8 カラ? )
extern	int			MakeARGB4ColorSoftImage( int SizeX, int SizeY ) ;																			// ?フトウエアで扱うイメ?ジの作成( ARGB4 カラ? )
extern	int			MakeRGB8ColorSoftImage( int SizeX, int SizeY ) ;																			// ?フトウエアで扱うイメ?ジの作成( RGB8 カラ? )
extern	int			MakePAL8ColorSoftImage( int SizeX, int SizeY ) ;																			// ?フトウエアで扱うイメ?ジの作成( パレット２５６色 カラ? )

extern	int			DeleteSoftImage( int SIHandle ) ;																							// ?フトウエアで扱うイメ?ジの解放

extern	int			GetSoftImageSize( int SIHandle, int *Width, int *Height ) ;																	// ?フトウエアで扱うイメ?ジのサイズを取得する
extern	int			CheckPaletteSoftImage( int SIHandle ) ;																						// ?フトウエアで扱うイメ?ジがパレット画像かどうかを取得する( TRUE:パレット画像  FALSE:パレット画像じゃない )
extern	int			CheckAlphaSoftImage( int SIHandle ) ;																						// ?フトウエアで扱うイメ?ジのフォ??ットにα要素があるかどうかを取得する( TRUE:ある  FALSE:ない )
extern	int			CheckPixelAlphaSoftImage( int SIHandle ) ;																					// ?フトウエアで扱うイメ?ジに含まれるピクセルのアルフ?値を?ェックする( 戻り値   -1:エラ?  0:画像にアルフ?成分が無い  1:画像にアルフ?成分があり、すべて最大(255)値  2:画像にアルフ?成分があり、存在するアルフ?値は最小(0)と最大(255)もしくは最小(0)のみ?3:画像にアルフ?成分があり、最小と最大以外の中間の値がある )  

extern	int			GetDrawScreenSoftImage( int x1, int y1, int x2, int y2, int SIHandle ) ;													// ?画対象の画面から指定領域のグラフィックを?フトウエアで扱うイメ?ジに?送する
extern	int			UpdateLayerdWindowForSoftImage( int SIHandle ) ;																			// ?フトウエアで扱うイメ?ジを使用して UpdateLayerdWindow を行う( イメ?ジはウインドウのクライアント領域と同じサイズである必要があります )
extern	int			FillSoftImage( int SIHandle, int r, int g, int b, int a ) ;																	// ?フトウエアで扱うイメ?ジを指定色で塗りつぶす(各色要素は０?２５５)
extern	int			ClearRectSoftImage( int SIHandle, int x, int y, int w, int h ) ;															// ?フトウエアで扱うイメ?ジの指定の領域を０クリアする
extern	int			GetPaletteSoftImage( int SIHandle, int PaletteNo, int *r, int *g, int *b, int *a ) ;										// ?フトウエアで扱うイメ?ジのパレットを取得する(各色要素は０?２５５)
extern	int			SetPaletteSoftImage( int SIHandle, int PaletteNo, int  r, int  g, int  b, int  a ) ;										// ?フトウエアで扱うイメ?ジのパレットをセットする(各色要素は０?２５５)
extern	int			DrawPixelPalCodeSoftImage( int SIHandle, int x, int y, int palNo ) ;														// ?フトウエアで扱うイメ?ジの指定座標にドットを?画する(パレット画像用、有効値は０?２５５)
extern	int			GetPixelPalCodeSoftImage( int SIHandle, int x, int y ) ;																	// ?フトウエアで扱うイメ?ジの指定座標の色コ?ドを取得する(パレット画像用、戻り値は０?２５５)
extern	void		*GetImageAddressSoftImage( int SIHandle ) ;																					// ?フトウエアで扱うイメ?ジの実イメ?ジが格?されているメモリ領域の先頭アドレスを取得する
extern	int			DrawPixelSoftImage( int SIHandle, int x, int y, int  r, int  g, int  b, int  a ) ;											// ?フトウエアで扱うイメ?ジの指定座標にドットを?画する(各色要素は０?２５５)
extern	int			GetPixelSoftImage(  int SIHandle, int x, int y, int *r, int *g, int *b, int *a ) ;											// ?フトウエアで扱うイメ?ジの指定座標の色を取得する(各色要素は０?２５５)
extern	int			DrawLineSoftImage(  int SIHandle, int x1, int y1, int x2, int y2, int r, int g, int b, int a ) ;							// ?フトウエアで扱うイメ?ジの指定座標に線を?画する(各色要素は０?２５５)
extern	int			BltSoftImage( int SrcX, int SrcY, int SrcSizeX, int SrcSizeY, int SrcSIHandle, int DestX, int DestY, int DestSIHandle ) ;	// ?フトウエアで扱うイメ?ジを別のイメ?ジ上に?送する
extern	int			BltSoftImageWithTransColor( int SrcX, int SrcY, int SrcSizeX, int SrcSizeY, int SrcSIHandle, int DestX, int DestY, int DestSIHandle, int Tr, int Tg, int Tb, int Ta ) ;	// ?フトウエアで扱うイメ?ジを透過色処理付きで?送する
extern	int			BltSoftImageWithAlphaBlend( int SrcX, int SrcY, int SrcSizeX, int SrcSizeY, int SrcSIHandle, int DestX, int DestY, int DestSIHandle, int Opacity = 255 ) ;	// ?フトウエアで扱うイメ?ジをアルフ?値のブレンドを考慮した上で?送する( Opacity は透明度 : 0( 完全透明 ) ? 255( 完全不透明 ) )( 出力先が ARGB8 ?式以外の場合はエラ?になります )
extern	int			ReverseSoftImageH( int SIHandle ) ;																							// ?フトウエアで扱うイメ?ジの左右を反?する
extern	int			ReverseSoftImageV( int SIHandle ) ;																							// ?フトウエアで扱うイメ?ジの上下を反?する
extern	int			ReverseSoftImage( int SIHandle ) ;																							// ?フトウエアで扱うイメ?ジの上下左右を反?する

extern	int			BltStringSoftImage( 
						int x, int y, const TCHAR *StrData,
						int DestSIHandle, int DestEdgeSIHandle = -1 ,
						int VerticalFlag = FALSE ) ;																							// ?フトウエアで扱うイメ?ジに文字列イメ?ジを?送する
extern	int			BltStringSoftImageToHandle( 
						int x, int y, const TCHAR *StrData,
						int DestSIHandle, int DestEdgeSIHandle /* 縁が必要ない場合は -1 */ ,
						int FontHandle, int VerticalFlag = FALSE ) ;																			// ?フトウエアで扱うイメ?ジに文字列イメ?ジを?送する( フォントハンドル使用版 )

extern	int			DrawSoftImage( int x, int y, int SIHandle ) ;																				// ?フトウエアで扱うイメ?ジを画面に?画する

extern	int			SaveSoftImageToBmp( const TCHAR *FilePath, int SIHandle ) ;																	// ?フトウエアで扱うイメ?ジをＢＭＰ画像フ?イルとして保存する
#ifndef DX_NON_PNGREAD
extern	int			SaveSoftImageToPng( const TCHAR *FilePath, int SIHandle, int CompressionLevel ) ;											// ?フトウエアで扱うイメ?ジをＰＮＧ画像フ?イルとして保存する CompressionLevel = 圧縮率、値が大きいほど高圧縮率高負荷、０は無圧縮,0?9
#endif
#ifndef DX_NON_JPEGREAD
extern	int			SaveSoftImageToJpeg( const TCHAR *FilePath, int SIHandle, int Quality, int Sample2x1 ) ;										// ?フトウエアで扱うイメ?ジをＪＰＥＧ画像フ?イルとして保存する Quality = 画質、値が大きいほど低圧縮高画質,0?100 
#endif

// 基?イメ?ジデ???造体関係
extern	int			CreateBaseImage(  const TCHAR *FileName, void *FileImage, int FileImageSize, int DataType /*=LOADIMAGE_TYPE_FILE*/ , BASEIMAGE *BaseImage, int ReverseFlag ) ;			// 各種グラフィックデ??から基?イメ?ジデ??を?築する
extern	int			CreateGraphImage( const TCHAR *FileName, void *DataImage, int DataImageSize, int DataImageType, BASEIMAGE *GraphImage, int ReverseFlag ) ;							// CreateBaseImage の旧名称
extern	int			CreateBaseImageToFile( const TCHAR *FileName,               BASEIMAGE *BaseImage, int ReverseFlag = FALSE ) ;														// 画像フ?イルから基?イメ?ジデ??を?築する
extern	int			CreateBaseImageToMem(  void *FileImage, int FileImageSize, BASEIMAGE *BaseImage, int ReverseFlag = FALSE ) ;														// メモリ上に展開された画像フ?イルから基?イメ?ジデ??を?築する
extern	int			CreateARGB8ColorBaseImage( int SizeX, int SizeY, BASEIMAGE *BaseImage ) ;																							// ?ＲＧＢ８カラ?の空の基?イメ?ジデ??を作成する
extern	int			CreateXRGB8ColorBaseImage( int SizeX, int SizeY, BASEIMAGE *BaseImage ) ;																							// ＸＲＧＢ８カラ?の空の基?イメ?ジデ??を作成する
extern	int			CreateRGB8ColorBaseImage( int SizeX, int SizeY, BASEIMAGE *BaseImage ) ;																							// ＲＧＢ８カラ?の空の基?イメ?ジデ??を作成する
extern	int			CreateARGB4ColorBaseImage( int SizeX, int SizeY, BASEIMAGE *BaseImage ) ;																							// ?ＲＧＢ４カラ?の空の基?イメ?ジデ??を作成する
extern	int			CreatePAL8ColorBaseImage( int SizeX, int SizeY, BASEIMAGE *BaseImage ) ;																							// パレット８ビットカラ?の空の基?イメ?ジデ??を作成する
extern	int			CreateColorDataBaseImage( int SizeX, int SizeY, COLORDATA *ColorData, BASEIMAGE *BaseImage ) ;																		// 指定のカラ?フォ??ットの殻の基?イメ?ジデ??を作成する

extern	int			ReleaseBaseImage(  BASEIMAGE *BaseImage ) ;																															// 基?イメ?ジデ??の後始末を行う
extern	int			ReleaseGraphImage( BASEIMAGE *GraphImage ) ;																														// ReleaseBaseImage の旧名称

extern	int			ConvertNormalFormatBaseImage( BASEIMAGE *BaseImage ) ;																												// DX_BASEIMAGE_FORMAT_NORMAL 以外の?式のイメ?ジデ??を DX_BASEIMAGE_FORMAT_NORMAL ?式のイメ?ジに変換する

extern	int			GetDrawScreenBaseImage( int x1, int y1, int x2, int y2, BASEIMAGE *BaseImage ) ;																					// ?画対象の画面から指定領域のグラフィックを基?イメ?ジデ??に?送する
extern	int			UpdateLayerdWindowForBaseImage( BASEIMAGE *BaseImage ) ;																											// 基?イメ?ジを使用して UpdateLayerdWindow を行う
extern	int			FillBaseImage( BASEIMAGE *BaseImage, int r, int g, int b, int a ) ;																									// 基?イメ?ジデ??を指定の色で塗りつぶす
extern	int			ClearRectBaseImage( BASEIMAGE *BaseImage, int x, int y, int w, int h ) ;																									// 基?イメ?ジデ??の指定の領域を０クリアする
extern	int			GetPaletteBaseImage( BASEIMAGE *BaseImage, int PaletteNo, int *r, int *g, int *b, int *a ) ;																		// 基?イメ?ジデ??のパレットを取得する
extern	int			SetPaletteBaseImage( BASEIMAGE *BaseImage, int PaletteNo, int  r, int  g, int  b, int  a ) ;																		// 基?イメ?ジデ??のパレットをセットする
extern	int			SetPixelPalCodeBaseImage( BASEIMAGE *BaseImage, int x, int y, int palNo ) ;																							// 基?イメ?ジデ??の指定の座標の色コ?ドを変更する(パレット画像用)
extern	int			GetPixelPalCodeBaseImage( BASEIMAGE *BaseImage, int x, int y ) ;																									// 基?イメ?ジデ??の指定の座標の色コ?ドを取得する(パレット画像用)
extern	int			SetPixelBaseImage( BASEIMAGE *BaseImage, int x, int y, int  r, int  g, int  b, int  a ) ;																			// 基?イメ?ジデ??の指定の座標の色を変更する(各色要素は０?２５５)
extern	int			GetPixelBaseImage( BASEIMAGE *BaseImage, int x, int y, int *r, int *g, int *b, int *a ) ;																			// 基?イメ?ジデ??の指定の座標の色を取得する(各色要素は０?２５５)
extern	int			DrawLineBaseImage( BASEIMAGE *BaseImage, int x1, int y1, int x2, int y2, int r, int g, int b, int a ) ;																// 基?イメ?ジデ??の指定の座標に線を?画する(各色要素は０?２５５)
extern	int			BltBaseImage( int SrcX, int SrcY, int SrcSizeX, int SrcSizeY, int DestX, int DestY, BASEIMAGE *SrcBaseImage, BASEIMAGE *DestBaseImage ) ;							// 基?イメ?ジデ??を?送する
extern	int			BltBaseImage( int DestX, int DestY, BASEIMAGE *SrcBaseImage, BASEIMAGE *DestBaseImage ) ;																			// 基?イメ?ジデ??を?送する
extern	int			BltBaseImageWithTransColor( int SrcX, int SrcY, int SrcSizeX, int SrcSizeY, int DestX, int DestY, BASEIMAGE *SrcBaseImage, BASEIMAGE *DestBaseImage, int Tr, int Tg, int Tb, int Ta ) ;	// 基?イメ?ジデ??を透過色処理付きで?送する
extern	int			BltBaseImageWithAlphaBlend( int SrcX, int SrcY, int SrcSizeX, int SrcSizeY, int DestX, int DestY, BASEIMAGE *SrcBaseImage, BASEIMAGE *DestBaseImage, int Opacity = 255 ) ;	// 基?イメ?ジデ??をアルフ?値のブレンドを考慮した上で?送する( Opacity は透明度 : 0( 完全透明 ) ? 255( 完全不透明 ) )( 出力先が ARGB8 ?式以外の場合はエラ?になります )
extern	int			ReverseBaseImageH( BASEIMAGE *BaseImage ) ;																															// 基?イメ?ジデ??の左右を反?する
extern	int			ReverseBaseImageV( BASEIMAGE *BaseImage ) ;																															// 基?イメ?ジデ??の上下を反?する
extern	int			ReverseBaseImage( BASEIMAGE *BaseImage ) ;																															// 基?イメ?ジデ??の上下左右を反?する
extern	int			CheckPixelAlphaBaseImage( BASEIMAGE *BaseImage ) ;																													// 基?イメ?ジデ??に含まれるピクセルのアルフ?値を?ェックする( 戻り値   -1:エラ?  0:画像にアルフ?成分が無い  1:画像にアルフ?成分があり、すべて最大(255)値  2:画像にアルフ?成分があり、存在するアルフ?値は最小(0)と最大(255)もしくは最小(0)のみ?3:画像にアルフ?成分があり、最小と最大以外の中間の値がある )  

extern	int			SaveBaseImageToBmp( const TCHAR *FilePath, BASEIMAGE *BaseImage ) ;																										// 基?画像デ??をＢＭＰ画像として保存する
#ifndef DX_NON_PNGREAD
extern	int			SaveBaseImageToPng( const TCHAR *FilePath, BASEIMAGE *BaseImage, int CompressionLevel ) ;																					// 基?画像デ??をＰＮＧ画像として保存する
#endif
#ifndef DX_NON_JPEGREAD
extern	int			SaveBaseImageToJpeg( const TCHAR *FilePath, BASEIMAGE *BaseImage, int Quality, int Sample2x1 ) ;																			// 基?画像デ??をＪＰＥＧ画像として保存する
#endif

// カラ??ッ?ングしながらグラフィックデ??間?送を行う Ver2
extern int			GraphColorMatchBltVer2( void *DestGraphData, int DestPitch, COLORDATA *DestColorData,
											void *SrcGraphData, int SrcPitch, COLORDATA *SrcColorData,
											void *AlphaMask, int AlphaPitch, COLORDATA *AlphaColorData,
											POINT DestPoint, RECT *SrcRect, int ReverseFlag,
											int TransColorAlphaTestFlag, unsigned int TransColor,
											int ImageShavedMode, int AlphaOnlyFlag = FALSE ,
											int RedIsAlphaFlag = FALSE , int TransColorNoMoveFlag = FALSE ,
											int Pal8ColorMatch = FALSE ) ;


// 色情報取得関係
extern	COLOR_F		GetColorF( float Red, float Green, float Blue, float Alpha ) ;										// 不動小数??のカラ?値を作成する
extern	COLOR_U8	GetColorU8( int Red, int Green, int Blue, int Alpha ) ;												// 符号なし整数８ビットのカラ?値を作成する
extern	DWORD		GetColor( int Red, int Green, int Blue ) ;															// ３原色値から現在の画面モ?ドに対応した色デ??値を得る
extern	int			GetColor2( int Color, int *Red, int *Green, int *Blue ) ;											// 画面モ?ドに対応した色デ??値から個々の３原色デ??を抜き出す
extern	int			GetColor3( COLORDATA *ColorData, int Red, int Green, int Blue, int Alpha = 255 ) ;					// ３原色値から指定のピクセルフォ??ットに対応した色デ??値を得る
extern	int			GetColor4( COLORDATA *DestColorData, COLORDATA* SrcColorData, int SrcColor ) ;						// ２つのカラ?フォ??ット間のデ??変換を行った情報を得る 
extern	int			GetColor5( COLORDATA *ColorData, int Color, int *Red, int *Green, int *Blue, int *Alpha = NULL ) ;	// 指定カラ?フォ??ットに対応した色デ??値から個々の３原色デ??を抜き出す
extern	int			CreatePaletteColorData( COLORDATA *ColorDataBuf ) ;													// パレットカラ?のカラ?情報を?築する
extern	int			CreateXRGB8ColorData( COLORDATA *ColorDataBuf ) ;													// ＸＲＧＢ８カラ?のカラ?情報を?築する
extern	int			CreateARGB8ColorData( COLORDATA *ColorDataBuf ) ;													// ?ＲＧＢ８カラ?のカラ?情報を?築する
extern	int			CreateARGB4ColorData( COLORDATA *ColorDataBuf ) ;													// ?ＲＧＢ４カラ?のカラ?情報を?築する
extern	int			CreateFullColorData( COLORDATA *ColorDataBuf ) ;													// フルカラ?ＤＩＢのカラ?情報を?築する
extern	int			CreateGrayColorData( COLORDATA *ColorDataBuf ) ;													// グレ?スケ?ルのカラ?情報を?築する
extern	int			CreatePal8ColorData( COLORDATA *ColorDataBuf ) ;													// パレット２５６色のカラ?情報を?築する
extern	int			CreateColorData( COLORDATA *ColorDataBuf, int ColorBitDepth,
									 DWORD RedMask, DWORD GreenMask, DWORD BlueMask, DWORD AlphaMask ) ;				// カラ?デ??を作成する
extern	void		SetColorDataNoneMask( COLORDATA *ColorData ) ;														// NoneMask 以外の要素を埋めた COLORDATA ?造体の情報を元に NoneMask をセットする
extern	int			CmpColorData( COLORDATA *ColorData1, COLORDATA *ColorData2 ) ;										// 二つのカラ?デ??が等しいかどうか調べる( TRUE:等しい  FALSE:等しくない )

#endif // DX_NOTUSE_DRAWFUNCTION












// DxSound.cpp関数プロト?イプ宣言

// サウンドデ??管理系関数
extern	int			InitSoundMem( int LogOutFlag = FALSE ) ;																// メモリに読みこんだWAVEデ??を削除し、初期化する

extern	int			AddSoundData( int Handle = -1 ) ;																		// 新しいサウンドデ??領域を確保する
extern	int			AddStreamSoundMem( STREAMDATA *Stream, int LoopNum,  int SoundHandle, int StreamDataType, int *CanStreamCloseFlag, int UnionHandle = -1 ) ;	// ストリ??風サウンドデ??にサウンドデ??を追加する
extern	int			AddStreamSoundMemToMem( void *FileImageBuffer, int ImageSize, int LoopNum,  int SoundHandle, int StreamDataType, int UnionHandle = -1 ) ;	// ストリ??風サウンドデ??にサウンドデ??を追加する
extern	int			AddStreamSoundMemToFile( const TCHAR *WaveFile, int LoopNum,  int SoundHandle, int StreamDataType, int UnionHandle = -1 ) ;	// ストリ??風サウンドデ??にサウンドデ??を追加する
extern	int			SetupStreamSoundMem( int SoundHandle ) ;																// ストリ??風サウンドデ??の再生?備を行う
extern	int			PlayStreamSoundMem( int SoundHandle, int PlayType = DX_PLAYTYPE_LOOP , int TopPositionFlag = TRUE ) ;	// ストリ??風サウンドデ??の再生開始
extern	int			CheckStreamSoundMem( int SoundHandle ) ;																// ストリ??風サウンドデ??の再生状態を得る
extern	int			StopStreamSoundMem( int SoundHandle ) ;																	// ストリ??風サウンドデ??の再生終了
extern	int			SetStreamSoundCurrentPosition( int Byte, int SoundHandle ) ;											// サウンドハンドルの再生位置をバイト単位で変更する(再生が?まっている時のみ有効)
extern	int			GetStreamSoundCurrentPosition( int SoundHandle ) ;														// サウンドハンドルの再生位置をバイト単位で取得する
extern	int			SetStreamSoundCurrentTime( int Time, int SoundHandle ) ;												// サウンドハンドルの再生位置を?リ秒単位で設定する(圧縮?式の場合は正しく設定されない場合がある)
extern	int			GetStreamSoundCurrentTime( int SoundHandle ) ;															// サウンドハンドルの再生位置を?リ秒単位で取得する(圧縮?式の場合は正しい値が返ってこない場合がある)
extern	int			ProcessStreamSoundMem( int SoundHandle ) ;																// ストリ??サウンドの再生処理関数
extern	int			ProcessStreamSoundMemAll( void ) ;																		// 有効なストリ??サウンドのすべて再生処理関数にかける


extern	int			LoadSoundMem2( const TCHAR *WaveName1, const TCHAR *WaveName2 ) ;											// 前奏部とル?プ部に分かれたサウンドデ??の作成
extern	int			LoadBGM( const TCHAR *WaveName ) ;																		// 主にＢＧＭを読み込むのに適した関数

extern	int			LoadSoundMemBase( const TCHAR *WaveName, int BufferNum, int UnionHandle = -1 ) ;							// サウンドデ??を追加する
extern	int			LoadSoundMem( const TCHAR *WaveName, int BufferNum = 3 , int UnionHandle = -1 ) ;						// サウンドデ??を追加する
extern	int			LoadSoundMemToBufNumSitei( const TCHAR *WaveName, int BufferNum ) ;										// 同時再生数指定?サウンド追加関数
extern	int			LoadSoundMemByResource( const TCHAR *ResourceName, const TCHAR *ResourceType, int BufferNum = 1 ) ;		// サウンドをリ??スから読み込む
extern	int			DuplicateSoundMem( int SrcSoundHandle, int BufferNum = 3 ) ;											// 同じサウンドデ??を使用するサウンドハンドルを作成する( DX_SOUNDDATATYPE_MEMNOPRESS ?イプのみ )

extern	int			LoadSoundMemByMemImageBase( void *FileImageBuffer, int ImageSize, int BufferNum, int UnionHandle = -1 ) ; // メモリ上に展開されたフ?イルイメ?ジからハンドルを作成する(ベ?ス関数)
extern	int			LoadSoundMemByMemImage( void *FileImageBuffer, int ImageSize, int UnionHandle = -1 ) ;					// メモリ上に展開されたフ?イルイメ?ジからハンドルを作成する(バッフ?数指定あり) 
extern	int			LoadSoundMemByMemImage2( void *UData, int UDataSize, WAVEFORMATEX *UFormat, int UHeaderSize ) ;			// メモリ上に展開されたフ?イルイメ?ジからハンドルを作成する2
extern	int			LoadSoundMemByMemImageToBufNumSitei( void *FileImageBuffer, int ImageSize, int BufferNum ) ;			// メモリ上に展開されたフ?イルイメ?ジからハンドルを作成する
extern	int			LoadSoundMem2ByMemImage( void *FileImageBuffer1, int ImageSize1, void *FileImageBuffer2, int ImageSize2 ) ;	// メモリ上に展開されたフ?イルイメ?ジから前奏部とル?プ部に分かれたハンドルを作成する
extern	int			LoadSoundMemFromSoftSound( int SoftSoundHandle, int BufferNum = 3 ) ;									// ?フトウエアで波?を制御するサウンドデ??からサウンドハンドルを作成する

extern	int			DeleteSoundMem( int SoundHandle, int LogOutFlag = FALSE ) ;												// メモリに読み込んだWAVEデ??を削除する

extern	int			PlaySoundMem( int SoundHandle, int PlayType, int TopPositionFlag = TRUE ) ;								// メモリに読みこんだWAVEデ??を再生する
extern	int			StopSoundMem( int SoundHandle ) ;																		// メモリに読み込んだWAVEデ??の再生を?める
extern	int			CheckSoundMem( int SoundHandle ) ;																		// メモリに読みこんだWAVEデ??が再生中か調べる
extern	int			SetPanSoundMem( int PanPal, int SoundHandle ) ;															// メモリに読みこんだWAVEデ??の再生にパンを設定する
extern	int			GetPanSoundMem( int SoundHandle ) ;																		// メモリに読みこんだWAVEデ??の再生にパンを取得する
extern	int			SetVolumeSoundMem( int VolumePal, int SoundHandle ) ;													// メモリに読みこんだWAVEデ??の再生に?リュ??を設定する( 100分の1デシベル単位 )
extern	int			ChangeVolumeSoundMem( int VolumePal, int SoundHandle ) ;												// メモリに読みこんだWAVEデ??の再生に?リュ??を設定する( パ?セント指定 )
extern	int			GetVolumeSoundMem( int SoundHandle ) ;																	// メモリに読みこんだWAVEデ??の再生の?リュ??を取得する
extern	int			SetFrequencySoundMem( int FrequencyPal, int SoundHandle ) ;												// メモリに読み込んだWAVEデ??の再生周波数を設定する
extern	int			GetFrequencySoundMem( int SoundHandle ) ;																// メモリに読み込んだWAVEデ??の再生周波数を取得する

extern	int			SetNextPlayPanSoundMem( int PanPal, int SoundHandle ) ;													// メモリに読みこんだWAVEデ??の次の再生にのみ使用するパンを設定する
extern	int			SetNextPlayVolumeSoundMem( int VolumePal, int SoundHandle ) ;											// メモリに読みこんだWAVEデ??の次の再生にのみ使用する?リュ??を設定する( 100分の1デシベル単位 )
extern	int			ChangeNextPlayVolumeSoundMem( int VolumePal, int SoundHandle ) ;										// メモリに読みこんだWAVEデ??の次の再生にのみ使用する?リュ??を設定する( パ?セント指定 )
extern	int			SetNextPlayFrequencySoundMem( int FrequencyPal, int SoundHandle ) ;										// メモリに読み込んだWAVEデ??の次の再生にのみ使用する再生周波数を設定する

extern	int			SetCurrentPositionSoundMem( int SamplePosition, int SoundHandle ) ;										// サウンドハンドルの再生位置をサンプル単位で変更する(再生が?まっている時のみ有効)
extern	int			GetCurrentPositionSoundMem( int SoundHandle ) ;															// サウンドハンドルの再生位置をサンプル単位で取得する
extern	int			SetSoundCurrentPosition( int Byte, int SoundHandle ) ;													// サウンドハンドルの再生位置をバイト単位で変更する(再生が?まっている時のみ有効)
extern	int			GetSoundCurrentPosition( int SoundHandle ) ;															// サウンドハンドルの再生位置をバイト単位で取得する
extern	int			SetSoundCurrentTime( int Time, int SoundHandle ) ;														// サウンドハンドルの再生位置を?リ秒単位で設定する(圧縮?式の場合は正しく設定されない場合がある)
extern	int			GetSoundCurrentTime( int SoundHandle ) ;																// サウンドハンドルの再生位置を?リ秒単位で取得する(圧縮?式の場合は正しい値が返ってこない場合がある)
extern	int			GetSoundTotalSample( int SoundHandle ) ;																// サウンドハンドルの音の総時間を取得する(単位はサンプル)
extern	int			GetSoundTotalTime( int SoundHandle ) ;																	// サウンドハンドルの音の総時間を取得する(単位は?リ秒)

extern	int			SetLoopPosSoundMem( int LoopTime, int SoundHandle ) ;													// サウンドハンドルにル?プ位置を設定する
extern	int			SetLoopTimePosSoundMem( int LoopTime, int SoundHandle ) ;												// サウンドハンドルにル?プ位置を設定する
extern	int			SetLoopSamplePosSoundMem( int LoopSamplePosition, int SoundHandle ) ;									// サウンドハンドルにル?プ位置を設定する

extern	int			SetLoopStartTimePosSoundMem( int LoopStartTime, int SoundHandle ) ;										// サウンドハンドルにル?プ開始位置を設定する
extern	int			SetLoopStartSamplePosSoundMem( int LoopStartSamplePosition, int SoundHandle ) ;							// サウンドハンドルにル?プ開始位置を設定する

// 設定関係関数
extern	int			SetCreateSoundDataType( int SoundDataType ) ;															// 作成するサウンドのデ???式を設定する( DX_SOUNDDATATYPE_MEMNOPRESS 等 )
extern	int			GetCreateSoundDataType( void ) ;																		// 作成するサウンドのデ???式を取得する( DX_SOUNDDATATYPE_MEMNOPRESS 等 )
extern	int			SetDisableReadSoundFunctionMask( int Mask ) ;															// 使用しないサウンドデ??読み込み処理の?スクを設定する( DX_READSOUNDFUNCTION_PCM 等 )
extern	int			GetDisableReadSoundFunctionMask( void ) ;																// 使用しないサウンドデ??読み込み処理の?スクを取得する( DX_READSOUNDFUNCTION_PCM 等 )
extern	int			SetEnableSoundCaptureFlag( int Flag ) ;																	// サウンドキャプ?ャを前提とした動作をするかどうかを設定する
extern	int			SetUseSoftwareMixingSoundFlag( int Flag ) ;																// サウンドの処理を?フトウエアで行うかどうかを設定する( TRUE:?フトウエア  FALSE:ハ?ドウエア( デフォルト ) )

// 情報取得系関数
extern	void*		GetDSoundObj( void ) ;	/* 戻り値を IDirectSound * にキャストして下さい */								// ＤＸライブラリが使用している DirectSound オブジェクトを取得する

#ifndef DX_NON_BEEP
// BEEP音再生用命令
extern	int			SetBeepFrequency( int Freq ) ;																			// ビ?プ音周波数設定関数
extern	int			PlayBeep( void ) ;																						// ビ?プ音を再生する
extern	int			StopBeep( void ) ;																						// ビ?プ音を?める
#endif

// ラッパ?関数
extern	int			PlaySoundFile( const TCHAR *FileName, int PlayType ) ;													// WAVEフ?イルを再生する
extern	int			PlaySound( const TCHAR *FileName, int PlayType ) ;														// PlaySoundFile の旧名称
extern	int			CheckSoundFile( void ) ;																				// WAVEフ?イルの再生中か調べる
extern	int			CheckSound( void ) ;																					// CheckSoundFile の旧名称
extern	int			StopSoundFile( void ) ;																					// WAVEフ?イルの再生を?める
extern	int			StopSound( void ) ;																						// StopSoundFile の旧名称
extern	int			SetVolumeSoundFile( int VolumePal ) ;																	// WAVEフ?イルの音量をセットする
extern	int			SetVolumeSound( int VolumePal ) ;																		// SetVolumeSound の旧名称

// ?フトウエア制御サウンド系関数
extern	int			InitSoftSound( void ) ;																					// ?フトウエアで扱う波?デ??をすべて解放する
extern	int			LoadSoftSound( const TCHAR *FileName ) ;																	// ?フトウエアで扱う波?デ??をフ?イルから作成する
extern	int			LoadSoftSoundFromMemImage( const void *FileImageBuffer, int FileImageSize ) ;							// ?フトウエアで扱う波?デ??をメモリ上に展開されたフ?イルイメ?ジから作成する
extern	int			MakeSoftSound( int UseFormat_SoftSoundHandle, int SampleNum ) ;											// ?フトウエアで扱う空の波?デ??を作成する( フォ??ットは引数の?フトウエアサウンドハンドルと同じものにする )
extern	int			MakeSoftSound2Ch16Bit44KHz( int SampleNum ) ;															// ?フトウエアで扱う空の波?デ??を作成する( ?ャンネル数:2 量子化ビット数:16bit サンプリング周波数:44KHz )
extern	int			MakeSoftSound2Ch16Bit22KHz( int SampleNum ) ;															// ?フトウエアで扱う空の波?デ??を作成する( ?ャンネル数:2 量子化ビット数:16bit サンプリング周波数:22KHz )
extern	int			MakeSoftSound2Ch8Bit44KHz( int SampleNum ) ;															// ?フトウエアで扱う空の波?デ??を作成する( ?ャンネル数:2 量子化ビット数:8bit サンプリング周波数:44KHz )
extern	int			MakeSoftSound2Ch8Bit22KHz( int SampleNum ) ;															// ?フトウエアで扱う空の波?デ??を作成する( ?ャンネル数:2 量子化ビット数:8bit サンプリング周波数:22KHz )
extern	int			MakeSoftSound1Ch16Bit44KHz( int SampleNum ) ;															// ?フトウエアで扱う空の波?デ??を作成する( ?ャンネル数:1 量子化ビット数:16bit サンプリング周波数:44KHz )
extern	int			MakeSoftSound1Ch16Bit22KHz( int SampleNum ) ;															// ?フトウエアで扱う空の波?デ??を作成する( ?ャンネル数:1 量子化ビット数:16bit サンプリング周波数:22KHz )
extern	int			MakeSoftSound1Ch8Bit44KHz( int SampleNum ) ;															// ?フトウエアで扱う空の波?デ??を作成する( ?ャンネル数:1 量子化ビット数:8bit サンプリング周波数:44KHz )
extern	int			MakeSoftSound1Ch8Bit22KHz( int SampleNum ) ;															// ?フトウエアで扱う空の波?デ??を作成する( ?ャンネル数:1 量子化ビット数:8bit サンプリング周波数:22KHz )
extern	int			DeleteSoftSound( int SoftSoundHandle ) ;																// ?フトウエアで扱う波?デ??を解放する
extern	int			SaveSoftSound( int SoftSoundHandle, const TCHAR *FileName ) ;											// ?フトウエアで扱う波?デ??を無圧縮Wav?式で保存する
extern	int			GetSoftSoundSampleNum( int SoftSoundHandle ) ;															// ?フトウエアで扱う波?デ??のサンプル数を取得する
extern	int			GetSoftSoundFormat( int SoftSoundHandle, int *Channels, int *BitsPerSample, int *SamplesPerSec ) ;		// ?フトウエアで扱う波?デ??のフォ??ットを取得する
extern	int			ReadSoftSoundData( int SoftSoundHandle, int SamplePosition, int *Channel1, int *Channel2 ) ;			// ?フトウエアで扱う波?デ??のサンプルを読み取る
extern	int			WriteSoftSoundData( int SoftSoundHandle, int SamplePosition, int Channel1, int Channel2 ) ;				// ?フトウエアで扱う波?デ??のサンプルを書き込む
extern	void		*GetSoftSoundDataImage( int SoftSoundHandle ) ;															// ?フトウエアで扱う波?デ??の波?イメ?ジが格?されているメモリアドレスを取得する

extern	int			InitSoftSoundPlayer( void ) ;																			// ?フトウエアで扱う波?デ??のプレイヤ?をすべて解放する
extern	int			MakeSoftSoundPlayer( int UseFormat_SoftSoundHandle ) ;													// ?フトウエアで扱う波?デ??のプレイヤ?を作成する( フォ??ットは引数の?フトウエアサウンドハンドルと同じものにする )
extern	int			MakeSoftSoundPlayer2Ch16Bit44KHz( void ) ;																// ?フトウエアで扱う波?デ??のプレイヤ?を作成する( ?ャンネル数:2 量子化ビット数:16bit サンプリング周波数:44KHz )
extern	int			MakeSoftSoundPlayer2Ch16Bit22KHz( void ) ;																// ?フトウエアで扱う波?デ??のプレイヤ?を作成する( ?ャンネル数:2 量子化ビット数:16bit サンプリング周波数:22KHz )
extern	int			MakeSoftSoundPlayer2Ch8Bit44KHz( void ) ;																// ?フトウエアで扱う波?デ??のプレイヤ?を作成する( ?ャンネル数:2 量子化ビット数:8bit サンプリング周波数:44KHz )
extern	int			MakeSoftSoundPlayer2Ch8Bit22KHz( void ) ;																// ?フトウエアで扱う波?デ??のプレイヤ?を作成する( ?ャンネル数:2 量子化ビット数:8bit サンプリング周波数:22KHz )
extern	int			MakeSoftSoundPlayer1Ch16Bit44KHz( void ) ;																// ?フトウエアで扱う波?デ??のプレイヤ?を作成する( ?ャンネル数:1 量子化ビット数:16bit サンプリング周波数:44KHz )
extern	int			MakeSoftSoundPlayer1Ch16Bit22KHz( void ) ;																// ?フトウエアで扱う波?デ??のプレイヤ?を作成する( ?ャンネル数:1 量子化ビット数:16bit サンプリング周波数:22KHz )
extern	int			MakeSoftSoundPlayer1Ch8Bit44KHz( void ) ;																// ?フトウエアで扱う波?デ??のプレイヤ?を作成する( ?ャンネル数:1 量子化ビット数:8bit サンプリング周波数:44KHz )
extern	int			MakeSoftSoundPlayer1Ch8Bit22KHz( void ) ;																// ?フトウエアで扱う波?デ??のプレイヤ?を作成する( ?ャンネル数:1 量子化ビット数:8bit サンプリング周波数:22KHz )
extern	int			DeleteSoftSoundPlayer( int SSoundPlayerHandle ) ;														// ?フトウエアで扱う波?デ??のプレイヤ?を削除する
extern	int			AddDataSoftSoundPlayer( int SSoundPlayerHandle, int SoftSoundHandle, int AddSamplePosition, int AddSampleNum ) ;	// ?フトウエアで扱う波?デ??のプレイヤ?に波?デ??を追加する( フォ??ットが同じではない場合はエラ? )
extern	int			AddDirectDataSoftSoundPlayer( int SSoundPlayerHandle, void *SoundData, int AddSampleNum ) ;							// ?フトウエアで扱う波?デ??のプレイヤ?にプレイヤ?が対応したフォ??ットの生波?デ??を追加する
extern	int			AddOneDataSoftSoundPlayer( int SSoundPlayerHandle, int Channel1, int Channel2 ) ;									// ?フトウエアで扱う波?デ??のプレイヤ?に波?デ??を一つ追加する
extern	int			GetSoftSoundPlayerFormat( int SSoundPlayerHandle, int *Channels, int *BitsPerSample, int *SamplesPerSec ) ;		// ?フトウエアで扱う波?デ??のプレイヤ?が扱うデ??フォ??ットを取得する
extern	int			StartSoftSoundPlayer( int SSoundPlayerHandle ) ;														// ?フトウエアで扱う波?デ??のプレイヤ?の再生処理を開始する
extern	int			CheckStartSoftSoundPlayer( int SSoundPlayerHandle ) ;													// ?フトウエアで扱う波?デ??のプレイヤ?の再生処理が開始されているか取得する( TRUE:開始している  FALSE:停?している )
extern	int			StopSoftSoundPlayer( int SSoundPlayerHandle ) ;															// ?フトウエアで扱う波?デ??のプレイヤ?の再生処理を停?する
extern	int			ResetSoftSoundPlayer( int SSoundPlayerHandle ) ;														// ?フトウエアで扱う波?デ??のプレイヤ?の状態を初期状態に戻す( 追加された波?デ??は削除され、再生状態だった場合は停?する )
extern	int			GetStockDataLengthSoftSoundPlayer( int SSoundPlayerHandle ) ;											// ?フトウエアで扱う波?デ??のプレイヤ?に追加した波?デ??でまだ再生用サウンドバッフ?に?送されていない波?デ??のサンプル数を取得する
extern	int			CheckSoftSoundPlayerNoneData( int SSoundPlayerHandle ) ;												// ?フトウエアで扱う波?デ??のプレイヤ?に再生用サウンドバッフ?に?送していない波?デ??が無く、再生用サウンドバッフ?にも無音デ??以外無いかどうかを取得する( TRUE:無音デ??以外無い  FALSE:有効デ??がある )




// ＭＩＤＩ制御関数
extern	int			AddMusicData( void ) ;																					// 新しいＭＩＤＩハンドルを取得する
extern	int			DeleteMusicMem( int MusicHandle ) ;																		// ＭＩＤＩハンドルを削除する
extern	int			LoadMusicMem( const TCHAR *FileName ) ;																	// ＭＩＤＩフ?イルを読み込む
extern	int			LoadMusicMemByMemImage( void *FileImageBuffer, int FileImageSize ) ;									// メモリ上に展開されたＭＩＤＩフ?イルを読み込む
extern	int			LoadMusicMemByResource( const TCHAR *ResourceName, const TCHAR *ResourceType ) ;							// リ??ス上のＭＩＤＩフ?イルを読み込む
extern	int			PlayMusicMem( int MusicHandle, int PlayType ) ;															// 読み込んだＭＩＤＩデ??の演奏を開始する
extern	int			StopMusicMem( int MusicHandle ) ;																		// ＭＩＤＩデ??の演奏を停?する
extern	int			CheckMusicMem( int MusicHandle ) ;																		// ＭＩＤＩデ??が演奏中かどうかを取得する( TRUE:演奏中  FALSE:停?中 )
extern	int			GetMusicMemPosition( int MusicHandle ) ;																// ＭＩＤＩデ??の現在の再生位置を取得する
extern	int			InitMusicMem( void ) ;																					// ＭＩＤＩデ??ハンドルをすべて削除する
extern	int			ProcessMusicMem( void ) ;																				// ＭＩＤＩデ??の周期的処理

extern	int			PlayMusic( const TCHAR *FileName, int PlayType ) ;														// ＭＩＤＩフ?イルを演奏する
extern	int			PlayMusicByMemImage( void *FileImageBuffer, int FileImageSize, int PlayType ) ;							// メモリ上に展開されているＭＩＤＩフ?イルを演奏する
extern	int			PlayMusicByResource( const TCHAR *ResourceName, const TCHAR *ResourceType, int PlayType ) ;				// リ??スからＭＩＤＩフ?イルを読み込んで演奏する
extern	int			SetVolumeMusic( int Volume ) ;																			// ＭＩＤＩの再生音量をセットする
extern	int			StopMusic( void ) ;																						// ＭＩＤＩフ?イルの演奏停?
extern	int			CheckMusic( void ) ;																					// ＭＩＤＩフ?イルが演奏中か否か情報を取得する
extern	int			GetMusicPosition( void ) ;																				// ＭＩＤＩの現在の再生位置を取得する

extern	int			SelectMidiMode( int Mode ) ;																			// ＭＩＤＩの再生?式をセットする











// DxArchive_.cpp 関数 プロト?イプ宣言
extern	int			DXArchivePreLoad( const TCHAR *FilePath , int ASync = FALSE ) ;						// 指定のＤＸ?フ?イルを丸ごとメモリに読み込む( 戻り値: -1=エラ?  0=成功 )
extern	int			DXArchiveCheckIdle( const TCHAR *FilePath ) ;										// 指定のＤＸ?フ?イルの事前読み込みが完了したかどうかを取得する( 戻り値： TRUE=完了した FALSE=まだ )
extern	int			DXArchiveRelease( const TCHAR *FilePath ) ;											// 指定のＤＸ?フ?イルをメモリから解放する
extern	int			DXArchiveCheckFile( const TCHAR *FilePath, const TCHAR *TargetFilePath ) ;			// ＤＸ?フ?イルの中に指定のフ?イルが存在するかどうかを調べる、TargetFilePath はＤＸ?フ?イルをカレントフォル?とした場合のパス( 戻り値:  -1=エラ?  0:無い  1:ある )





















// DxModel.cpp 関数 プロト?イプ宣言

#ifndef DX_NON_MODEL

// モデルの読み込み・複製関係
extern	int			MV1LoadModel( const TCHAR *FileName ) ;														// モデルの読み込み( -1:エラ?  0以上:モデルハンドル )
extern	int			MV1LoadModelFromMem( void *FileImage, int FileSize, int (* FileReadFunc )( const TCHAR *FilePath, void **FileImageAddr, int *FileSize, void *FileReadFuncData ), int (* FileReleaseFunc )( void *MemoryAddr, void *FileReadFuncData ), void *FileReadFuncData = NULL ) ;	// メモリ上のモデルフ?イルイメ?ジと独自の読み込みル??ンを使用してモデルを読み込む
extern	int			MV1DuplicateModel( int SrcMHandle ) ;														// 指定のモデルと同じモデル基?デ??を使用してモデルを作成する( -1:エラ?  0以上:モデルハンドル )
extern	int			MV1CreateCloneModel( int SrcMHandle ) ;														// 指定のモデルをモデル基?デ??も含め複製する( MV1DuplicateModel はモデル基?デ??は共有しますが、こちらは複製元のモデルとは一切共有デ??の無いモデルハンドルを作成します )( -1:エラ?  0以上:モデルハンドル )

extern	int			MV1DeleteModel( int MHandle ) ;																// モデルを削除する

extern	int			MV1SetLoadModelReMakeNormal( int Flag ) ;													// モデルを読み込む際に?線の再計算を行うかどうかを設定する( TRUE:行う  FALSE:行わない )
extern	int			MV1SetLoadModelReMakeNormalSmoothingAngle( float SmoothingAngle = 1.562069f ) ;				// モデルを読み込む際に行う?泉の再計算で使用するス??ジング角度を設定する( 単位はラジアン )
extern	int			MV1SetLoadModelPositionOptimize( int Flag ) ;												// モデルを読み込む際に座標デ??の最適化を行うかどうかを設定する( TRUE:行う  FALSE:行わない )

// モデル?画関係
extern	int			MV1DrawModel( int MHandle ) ;																// モデルを?画する
extern	int			MV1DrawFrame( int MHandle, int FrameIndex ) ;												// モデルの指定のフレ??を?画する
extern	int			MV1DrawMesh( int MHandle, int MeshIndex ) ;													// モデルの指定のメッシュを?画する
extern	int			MV1DrawModelDebug( int MHandle, int Color, int IsNormalLine, float NormalLineLength, int IsPolyLine, int IsCollisionBox ) ;	// モデルのデバッグ?画

// モデル基?制御関係
extern	MATRIX		MV1GetLocalWorldMatrix( int MHandle ) ;														// モデルのロ?カル座標からワ?ルド座標に変換する行列を得る
extern	int			MV1SetPosition( int MHandle, VECTOR Position ) ;											// モデルの座標をセット
extern	VECTOR		MV1GetPosition( int MHandle ) ;																// モデルの座標を取得
extern	int			MV1SetScale( int MHandle, VECTOR Scale ) ;													// モデルの拡大値をセット
extern	VECTOR		MV1GetScale( int MHandle ) ;																// モデルの拡大値を取得
extern	int			MV1SetRotationXYZ( int MHandle, VECTOR Rotate ) ;											// モデルの回?値をセット( X軸回?→Y軸回?→Z軸回?方式 )
extern	VECTOR		MV1GetRotationXYZ( int MHandle ) ;															// モデルの回?値を取得( X軸回?→Y軸回?→Z軸回?方式 )
extern	int			MV1SetRotationZYAxis( int MHandle, VECTOR ZAxisDirection, VECTOR YAxisDirection, float ZAxisTwistRotate ) ;	// モデルのＺ軸とＹ軸の向きをセットする
extern	int			MV1SetRotationMatrix( int MHandle, MATRIX Matrix ) ;										// モデルの回?用行列をセットする
extern	MATRIX		MV1GetRotationMatrix( int MHandle ) ;														// モデルの回?用行列を取得する
extern	int			MV1SetMatrix( int MHandle, MATRIX Matrix ) ;												// モデルの変?用行列をセットする
extern	MATRIX		MV1GetMatrix( int MHandle ) ;																// モデルの変?用行列を取得する
extern	int			MV1SetVisible( int MHandle, int VisibleFlag ) ;												// モデルの?示、非?示状態を変更する( TRUE:?示  FALSE:非?示 )
extern	int			MV1GetVisible( int MHandle ) ;																// モデルの?示、非?示状態を取得する( TRUE:?示  FALSE:非?示 )
extern	int			MV1SetDifColorScale( int MHandle, COLOR_F Scale ) ;											// モデルのディフュ?ズカラ?のスケ?ル値を設定する( デフォルト値は 1.0f )
extern	COLOR_F		MV1GetDifColorScale( int MHandle ) ;														// モデルのディフュ?ズカラ?のスケ?ル値を取得する( デフォルト値は 1.0f )
extern	int			MV1SetSpcColorScale( int MHandle, COLOR_F Scale ) ;											// モデルのスペキュラカラ?のスケ?ル値を設定する( デフォルト値は 1.0f )
extern	COLOR_F		MV1GetSpcColorScale( int MHandle ) ;														// モデルのスペキュラカラ?のスケ?ル値を取得する( デフォルト値は 1.0f )
extern	int			MV1SetEmiColorScale( int MHandle, COLOR_F Scale ) ;											// モデルのエ?ッシブカラ?のスケ?ル値を設定する( デフォルト値は 1.0f )
extern	COLOR_F		MV1GetEmiColorScale( int MHandle ) ;														// モデルのエ?ッシブカラ?のスケ?ル値を取得する( デフォルト値は 1.0f )
extern	int			MV1SetAmbColorScale( int MHandle, COLOR_F Scale ) ;											// モデルのアンビエントカラ?のスケ?ル値を設定する( デフォルト値は 1.0f )
extern	COLOR_F		MV1GetAmbColorScale( int MHandle ) ;														// モデルのアンビエントカラ?のスケ?ル値を取得する( デフォルト値は 1.0f )
extern	int			MV1GetSemiTransState( int MHandle ) ;														// モデルに半透明要素があるかどうかを取得する( 戻り値 TRUE:ある  FALSE:ない )
extern	int			MV1SetOpacityRate( int MHandle, float Rate ) ;												// モデルの不透明度を設定する( 不透明 1.0f ? 透明 0.0f )
extern	float		MV1GetOpacityRate( int MHandle ) ;															// モデルの不透明度を取得する( 不透明 1.0f ? 透明 0.0f )
extern	int			MV1SetUseZBuffer( int MHandle, int Flag ) ;													// モデルを?画する際にＺバッフ?を使用するかどうかを設定する
extern	int			MV1SetWriteZBuffer( int MHandle, int Flag ) ;												// モデルを?画する際にＺバッフ?に書き込みを行うかどうかを設定する
extern	int			MV1SetZBufferCmpType( int MHandle, int CmpType /* DX_CMP_NEVER 等 */ ) ;					// モデルの?画時のＺ値の比較モ?ドを設定する
extern	int			MV1SetZBias( int MHandle, int Bias ) ;														// モデルの?画時の書き込むＺ値のバイアスを設定する
extern	int			MV1SetUseVertDifColor( int MHandle, int UseFlag ) ;											// モデルの含まれるメッシュの頂?ディフュ?ズカラ?を?テリアルのディフュ?ズカラ?の代わりに使用するかどうかを設定する( TRUE:?テリアルカラ?の代わりに使用する  FALSE:?テリアルカラ?を使用する )
extern	int			MV1SetUseVertSpcColor( int MHandle, int UseFlag ) ;											// モデルに含まれるメッシュの頂?スペキュラカラ?を?テリアルのスペキュラカラ?の代わりに使用するかどうかを設定する( TRUE:?テリアルカラ?の代わりに使用する  FALSE:?テリアルカラ?を使用する )
extern	int			MV1SetSampleFilterMode( int MHandle, int FilterMode ) ;										// モデルのテクス?ャのサンプルフィル??モ?ドを変更する( FilterMode は DX_DRAWMODE_NEAREST 等 )
extern	int			MV1SetMaxAnisotropy( int MHandle, int MaxAnisotropy ) ;										// モデルの異方性フィル?リングの最大次数を設定する
extern	int			MV1SetWireFrameDrawFlag( int MHandle, int Flag ) ;											// モデルをワイヤ?フレ??で?画するかどうかを設定する
extern	int			MV1RefreshVertColorFromMaterial( int MHandle ) ;											// モデルの頂?カラ?を現在設定されている?テリアルのカラ?にする

// アニメ?ション関係
extern	int			MV1AttachAnim( int MHandle, int AnimIndex, int AnimSrcMHandle = -1 , int NameCheck = TRUE ) ;	// アニメ?ションをア?ッ?する( 戻り値  -1:エラ?  0以上:ア?ッ?インデックス )
extern	int			MV1DetachAnim( int MHandle, int AttachIndex ) ;												// アニメ?ションをデ?ッ?する
extern	int			MV1SetAttachAnimTime( int MHandle, int AttachIndex, float Time ) ;							// ア?ッ?しているアニメ?ションの再生時間を設定する
extern	float		MV1GetAttachAnimTime( int MHandle, int AttachIndex ) ;										// ア?ッ?しているアニメ?ションの再生時間を取得する
extern	float		MV1GetAttachAnimTotalTime( int MHandle, int AttachIndex ) ;									// ア?ッ?しているアニメ?ションの総時間を得る
extern	int			MV1SetAttachAnimBlendRate( int MHandle, int AttachIndex, float Rate = 1.0f ) ;				// ア?ッ?しているアニメ?ションのブレンド率を設定する
extern	float		MV1GetAttachAnimBlendRate( int MHandle, int AttachIndex ) ;									// ア?ッ?しているアニメ?ションのブレンド率を取得する
extern	int			MV1SetAttachAnimBlendRateToFrame( int MHandle, int AttachIndex, int FrameIndex, float Rate, int SetChild = TRUE ) ;	// ア?ッ?しているアニメ?ションのブレンド率を設定する( フレ??単位 )
extern	float		MV1GetAttachAnimBlendRateToFrame( int MHandle, int AttachIndex, int FrameIndex ) ;			// ア?ッ?しているアニメ?ションのブレンド率を設定する( フレ??単位 )
extern	int			MV1GetAttachAnim( int MHandle, int AttachIndex ) ;											// ア?ッ?しているアニメ?ションのアニメ?ションインデックスを取得する

extern	int			MV1GetAnimNum( int MHandle ) ;																// アニメ?ションの数を取得する
extern	const TCHAR *MV1GetAnimName( int MHandle, int AnimIndex ) ;												// 指定番号のアニメ?ション名を取得する( NULL:エラ? )
extern	int			MV1GetAnimIndex( int MHandle, const TCHAR *AnimName ) ;										// 指定名のアニメ?ション番号を取得する( -1:エラ? )
extern	float		MV1GetAnimTotalTime( int MHandle, int AnimIndex ) ;											// 指定番号のアニメ?ションの総時間を得る
extern	int			MV1GetAnimTargetFrameNum( int MHandle, int AnimIndex ) ;									// 指定のアニメ?ションが??ゲットとするフレ??の数を取得する
extern	const TCHAR *MV1GetAnimTargetFrameName( int MHandle, int AnimIndex, int AnimFrameIndex ) ;				// 指定のアニメ?ションが??ゲットとするフレ??の名前を取得する
extern	int			MV1GetAnimTargetFrame( int MHandle, int AnimIndex, int AnimFrameIndex ) ;					// 指定のアニメ?ションが??ゲットとするフレ??の番号を取得する
extern	int			MV1GetAnimTargetFrameKeySetNum( int MHandle, int AnimIndex, int AnimFrameIndex ) ;			// 指定のアニメ?ションが??ゲットとするフレ??用のアニメ?ションキ?セットの数を取得する
extern	int			MV1GetAnimTargetFrameKeySet( int MHandle, int AnimIndex, int AnimFrameIndex, int Index ) ;	// 指定のアニメ?ションが??ゲットとするフレ??用のアニメ?ションキ?セットキ?セットインデックスを取得する

extern	int			MV1GetAnimKeySetNum( int MHandle ) ;														// モデルに含まれるアニメ?ションキ?セットの総数を得る
extern	int			MV1GetAnimKeySetType( int MHandle, int AnimKeySetIndex ) ;									// 指定のアニメ?ションキ?セットの?イプを取得する( MV1_ANIMKEY_TYPE_QUATERNION 等 )
extern	int			MV1GetAnimKeySetDataType( int MHandle, int AnimKeySetIndex ) ;								// 指定のアニメ?ションキ?セットのデ???イプを取得する( MV1_ANIMKEY_DATATYPE_ROTATE 等 )
extern	int			MV1GetAnimKeySetTimeType( int MHandle, int AnimKeySetIndex ) ;								// 指定のアニメ?ションキ?セットのキ?の時間デ???イプを取得する( MV1_ANIMKEY_TIME_TYPE_ONE 等 )
extern	int			MV1GetAnimKeySetDataNum( int MHandle, int AnimKeySetIndex ) ;								// 指定のアニメ?ションキ?セットのキ?の数を取得する
extern	float		MV1GetAnimKeyDataTime( int MHandle, int AnimKeySetIndex, int Index ) ;						// 指定のアニメ?ションキ?セットのキ?の時間を取得する
extern	FLOAT4		MV1GetAnimKeyDataToQuaternion( int MHandle, int AnimKeySetIndex, int Index ) ;				// 指定のアニメ?ションキ?セットのキ?を取得する、キ??イプが MV1_ANIMKEY_TYPE_QUATERNION では無かった場合は失敗する
extern	FLOAT4		MV1GetAnimKeyDataToQuaternionFromTime( int MHandle, int AnimKeySetIndex, float Time ) ;		// 指定のアニメ?ションキ?セットのキ?を取得する、キ??イプが MV1_ANIMKEY_TYPE_QUATERNION では無かった場合は失敗する( 時間指定版 )
extern	VECTOR		MV1GetAnimKeyDataToVector( int MHandle, int AnimKeySetIndex, int Index ) ;					// 指定のアニメ?ションキ?セットのキ?を取得する、キ??イプが MV1_ANIMKEY_TYPE_VECTOR では無かった場合は失敗する
extern	VECTOR		MV1GetAnimKeyDataToVectorFromTime( int MHandle, int AnimKeySetIndex, float Time ) ;			// 指定のアニメ?ションキ?セットのキ?を取得する、キ??イプが MV1_ANIMKEY_TYPE_VECTOR では無かった場合は失敗する( 時間指定版 )
extern	MATRIX		MV1GetAnimKeyDataToMatrix( int MHandle, int AnimKeySetIndex, int Index ) ;					// 指定のアニメ?ションキ?セットのキ?を取得する、キ??イプが MV1_ANIMKEY_TYPE_MATRIX4X4C か MV1_ANIMKEY_TYPE_MATRIX3X3 では無かった場合は失敗する
extern	MATRIX		MV1GetAnimKeyDataToMatrixFromTime( int MHandle, int AnimKeySetIndex, float Time ) ;			// 指定のアニメ?ションキ?セットのキ?を取得する、キ??イプが MV1_ANIMKEY_TYPE_MATRIX4X4C か MV1_ANIMKEY_TYPE_MATRIX3X3 では無かった場合は失敗する( 時間指定版 )
extern	float		MV1GetAnimKeyDataToFlat( int MHandle, int AnimKeySetIndex, int Index ) ;					// 指定のアニメ?ションキ?セットのキ?を取得する、キ??イプが MV1_ANIMKEY_TYPE_FLAT では無かった場合は失敗する
extern	float		MV1GetAnimKeyDataToFlatFromTime( int MHandle, int AnimKeySetIndex, float Time ) ;			// 指定のアニメ?ションキ?セットのキ?を取得する、キ??イプが MV1_ANIMKEY_TYPE_FLAT では無かった場合は失敗する( 時間指定版 )
extern	float		MV1GetAnimKeyDataToLinear( int MHandle, int AnimKeySetIndex, int Index ) ;					// 指定のアニメ?ションキ?セットのキ?を取得する、キ??イプが MV1_ANIMKEY_TYPE_LINEAR では無かった場合は失敗する
extern	float		MV1GetAnimKeyDataToLinearFromTime( int MHandle, int AnimKeySetIndex, float Time ) ;			// 指定のアニメ?ションキ?セットのキ?を取得する、キ??イプが MV1_ANIMKEY_TYPE_LINEAR では無かった場合は失敗する( 時間指定版 )

// ?テリアル関係
extern	int			MV1GetMaterialNum( int MHandle ) ;															// モデルで使用している?テリアルの数を取得する
extern	const TCHAR *MV1GetMaterialName( int MHandle, int MaterialIndex ) ;										// 指定の?テリアルの名前を取得する
extern	int			MV1SetMaterialType( int MHandle, int MaterialIndex, int Type ) ;							// 指定の?テリアルの?イプを変更する( Type : DX_MATERIAL_TYPE_NORMAL など )
extern	int			MV1GetMaterialType( int MHandle, int MaterialIndex ) ;										// 指定の?テリアルの?イプを取得する( 戻り値 : DX_MATERIAL_TYPE_NORMAL など )
extern	int			MV1SetMaterialDifColor( int MHandle, int MaterialIndex, COLOR_F Color ) ;					// 指定の?テリアルのディフュ?ズカラ?を設定する
extern	COLOR_F		MV1GetMaterialDifColor( int MHandle, int MaterialIndex ) ;									// 指定の?テリアルのディフュ?ズカラ?を取得する
extern	int			MV1SetMaterialSpcColor( int MHandle, int MaterialIndex, COLOR_F Color ) ;					// 指定の?テリアルのスペキュラカラ?を設定する
extern	COLOR_F		MV1GetMaterialSpcColor( int MHandle, int MaterialIndex ) ;									// 指定の?テリアルのスペキュラカラ?を取得する
extern	int			MV1SetMaterialEmiColor( int MHandle, int MaterialIndex, COLOR_F Color ) ;					// 指定の?テリアルのエ?ッシブカラ?を設定する
extern	COLOR_F		MV1GetMaterialEmiColor( int MHandle, int MaterialIndex ) ;									// 指定の?テリアルのエ?ッシブカラ?を取得する
extern	int			MV1SetMaterialAmbColor( int MHandle, int MaterialIndex, COLOR_F Color ) ;					// 指定の?テリアルのアンビエントカラ?を設定する
extern	COLOR_F		MV1GetMaterialAmbColor( int MHandle, int MaterialIndex ) ;									// 指定の?テリアルのアンビエントカラ?を取得する
extern	int			MV1SetMaterialSpcPower( int MHandle, int MaterialIndex, float Power ) ;						// 指定の?テリアルのスペキュラの強さを設定する
extern	float		MV1GetMaterialSpcPower( int MHandle, int MaterialIndex ) ;									// 指定の?テリアルのスペキュラの強さを取得する
extern	int			MV1SetMaterialDifMapTexture( int MHandle, int MaterialIndex, int TexIndex ) ;				// 指定の?テリアルでディフュ?ズ?ップとして使用するテクス?ャを指定する
extern	int			MV1GetMaterialDifMapTexture( int MHandle, int MaterialIndex ) ;								// 指定の?テリアルでディフュ?ズ?ップとして使用されているテクス?ャのインデックスを取得する
extern	int			MV1SetMaterialSpcMapTexture( int MHandle, int MaterialIndex, int TexIndex ) ;				// 指定の?テリアルでスペキュラ?ップとして使用するテクス?ャを指定する
extern	int			MV1GetMaterialSpcMapTexture( int MHandle, int MaterialIndex ) ;								// 指定の?テリアルでスペキュラ?ップとして使用されているテクス?ャのインデックスを取得する
extern	int			MV1GetMaterialNormalMapTexture( int MHandle, int MaterialIndex ) ;							// 指定の?テリアルで?線?ップとして使用されているテクス?ャのインデックスを取得する
extern	int			MV1SetMaterialDifGradTexture( int MHandle, int MaterialIndex, int TexIndex ) ;				// 指定の?テリアルでトゥ?ンレン?リングのディフュ?ズグラデ?ション?ップとして使用するテクス?ャを設定する
extern	int			MV1GetMaterialDifGradTexture( int MHandle, int MaterialIndex ) ;							// 指定の?テリアルでトゥ?ンレン?リングのディフュ?ズグラデ?ション?ップとして使用するテクス?ャを取得する
extern	int			MV1SetMaterialSpcGradTexture( int MHandle, int MaterialIndex, int TexIndex ) ;				// 指定の?テリアルでトゥ?ンレン?リングのスペキュラグラデ?ション?ップとして使用するテクス?ャを設定する
extern	int			MV1GetMaterialSpcGradTexture( int MHandle, int MaterialIndex ) ;							// 指定の?テリアルでトゥ?ンレン?リングのスペキュラグラデ?ション?ップとして使用するテクス?ャを取得する
extern	int			MV1SetMaterialDifGradBlendType( int MHandle, int MaterialIndex, int BlendType ) ;			// 指定の?テリアルのトゥ?ンレン?リングで使用するディフュ?ズグラデ?ション?ップとディフュ?ズカラ?の合成方?を設定する( DX_MATERIAL_BLENDTYPE_ADDITIVE など )
extern	int			MV1GetMaterialDifGradBlendType( int MHandle, int MaterialIndex ) ;							// 指定の?テリアルのトゥ?ンレン?リングで使用するディフュ?ズグラデ?ション?ップとディフュ?ズカラ?の合成方?を取得する( DX_MATERIAL_BLENDTYPE_ADDITIVE など )
extern	int			MV1SetMaterialSpcGradBlendType( int MHandle, int MaterialIndex, int BlendType ) ;			// 指定の?テリアルのトゥ?ンレン?リングで使用するスペキュラグラデ?ション?ップとスペキュラカラ?の合成方?を設定する( DX_MATERIAL_BLENDTYPE_ADDITIVE など )
extern	int			MV1GetMaterialSpcGradBlendType( int MHandle, int MaterialIndex ) ;							// 指定の?テリアルのトゥ?ンレン?リングで使用するスペキュラグラデ?ション?ップとスペキュラカラ?の合成方?を取得する( DX_MATERIAL_BLENDTYPE_ADDITIVE など )
extern	int			MV1SetMaterialOutLineWidth( int MHandle, int MaterialIndex, float Width ) ;					// 指定の?テリアルのトゥ?ンレン?リングで使用する輪郭線の太さを設定する
extern	float		MV1GetMaterialOutLineWidth( int MHandle, int MaterialIndex ) ;								// 指定の?テリアルのトゥ?ンレン?リングで使用する輪郭線の太さを取得する
extern	int			MV1SetMaterialOutLineDotWidth( int MHandle, int MaterialIndex, float Width ) ;				// 指定の?テリアルのトゥ?ンレン?リングで使用する輪郭線のドット単位の太さを設定する
extern	float		MV1GetMaterialOutLineDotWidth( int MHandle, int MaterialIndex ) ;							// 指定の?テリアルのトゥ?ンレン?リングで使用する輪郭線のドット単位の太さを取得する
extern	int			MV1SetMaterialOutLineColor( int MHandle, int MaterialIndex, COLOR_F Color ) ;				// 指定の?テリアルのトゥ?ンレン?リングで使用する輪郭線の色を設定する
extern	COLOR_F		MV1GetMaterialOutLineColor( int MHandle, int MaterialIndex ) ;								// 指定の?テリアルのトゥ?ンレン?リングで使用する輪郭線の色を取得する
extern	int			MV1SetMaterialDrawBlendMode( int MHandle, int MaterialIndex, int BlendMode ) ;				// 指定の?テリアルの?画ブレンドモ?ドを設定する( DX_BLENDMODE_ALPHA 等 )
extern	int			MV1GetMaterialDrawBlendMode( int MHandle, int MaterialIndex ) ;								// 指定の?テリアルの?画ブレンドモ?ドを取得する( DX_BLENDMODE_ALPHA 等 )
extern	int			MV1SetMaterialDrawBlendParam( int MHandle, int MaterialIndex, int BlendParam ) ;			// 指定の?テリアルの?画ブレンドパラメ??を設定する
extern	int			MV1GetMaterialDrawBlendParam( int MHandle, int MaterialIndex ) ;							// 指定の?テリアルの?画ブレンドパラメ??を設定する

// テクス?ャ関係
extern	int			MV1GetTextureNum( int MHandle ) ;															// テクス?ャの数を取得
extern	const TCHAR *MV1GetTextureName( int MHandle, int TexIndex ) ;											// テクス?ャの名前を取得
extern	int			MV1SetTextureColorFilePath( int MHandle, int TexIndex, const TCHAR *FilePath ) ;			// カラ?テクス?ャのフ?イルパスを変更する
extern	const TCHAR *MV1GetTextureColorFilePath( int MHandle, int TexIndex ) ;									// カラ?テクス?ャのフ?イルパスを取得
extern	int			MV1SetTextureAlphaFilePath( int MHandle, int TexIndex, const TCHAR *FilePath ) ;			// アルフ?テクス?ャのフ?イルパスを変更する
extern	const TCHAR *MV1GetTextureAlphaFilePath( int MHandle, int TexIndex ) ;									// アルフ?テクス?ャのフ?イルパスを取得
extern	int			MV1SetTextureGraphHandle( int MHandle, int TexIndex, int GrHandle, int SemiTransFlag ) ;	// テクス?ャで使用するグラフィックハンドルを変更する( GrHandle を -1 にすると解除 )
extern	int			MV1GetTextureGraphHandle( int MHandle, int TexIndex ) ;										// テクス?ャのグラフィックハンドルを取得する
extern	int			MV1SetTextureAddressMode( int MHandle, int TexIndex, int AddrUMode, int AddrVMode ) ;		// テクス?ャのアドレスモ?ドを設定する( AddUMode の値は DX_TEXADDRESS_WRAP 等 )
extern	int			MV1GetTextureAddressModeU( int MHandle, int TexIndex ) ;									// テクス?ャのＵ値のアドレスモ?ドを取得する( 戻り値:DX_TEXADDRESS_WRAP 等 )
extern	int			MV1GetTextureAddressModeV( int MHandle, int TexIndex ) ;									// テクス?ャのＶ値のアドレスモ?ドを取得する( 戻り値:DX_TEXADDRESS_WRAP 等 )
extern	int			MV1GetTextureWidth( int MHandle, int TexIndex ) ;											// テクス?ャの幅を取得する
extern	int			MV1GetTextureHeight( int MHandle, int TexIndex ) ;											// テクス?ャの高さを取得する
extern	int			MV1GetTextureSemiTransState( int MHandle, int TexIndex ) ;									// テクス?ャに半透明要素があるかどうかを取得する( 戻り値  TRUE:ある  FALSE:ない )
extern	int			MV1SetTextureBumpImageFlag( int MHandle, int TexIndex, int Flag ) ;							// テクス?ャで使用している画像がバンプ?ップかどうかを設定する
extern	int			MV1GetTextureBumpImageFlag( int MHandle, int TexIndex ) ;									// テクス?ャがバンプ?ップかどうかを取得する( 戻り値  TRUE:バンプ?ップ  FALSE:違う )
extern	int			MV1SetTextureBumpImageNextPixelLength( int MHandle, int TexIndex, float Length ) ;			// バンプ?ップ画像の場合の隣のピクセルとの距離を設定する
extern	float		MV1GetTextureBumpImageNextPixelLength( int MHandle, int TexIndex ) ;						// バンプ?ップ画像の場合の隣のピクセルとの距離を取得する
extern	int			MV1SetTextureSampleFilterMode( int MHandle, int TexIndex, int FilterMode ) ;				// テクス?ャのフィル?リングモ?ドを設定する
extern	int			MV1GetTextureSampleFilterMode( int MHandle, int TexIndex ) ;								// テクス?ャのフィル?リングモ?ドを取得する( 戻り値  DX_DRAWMODE_BILINEAR等 )
extern	int			MV1LoadTexture( const TCHAR *FilePath ) ;													// ３Ｄモデルに?り付けるのに向いた画像の読み込み方式で画像を読み込む( 戻り値  -1:エラ?  0以上:グラフィックハンドル )

// フレ??関係
extern	int			MV1GetFrameNum( int MHandle ) ;																// フレ??の数を取得する
extern	int			MV1SearchFrame( int MHandle, const TCHAR *FrameName ) ;										// フレ??の名前からモデル中のフレ??のフレ??インデックスを取得する( 無かった場合は戻り値が-1 )
extern	int			MV1SearchFrameChild( int MHandle, int FrameIndex = -1 , const TCHAR *ChildName = NULL ) ;	// フレ??の名前から指定のフレ??の子フレ??のフレ??インデックスを取得する( 名前指定版 )( FrameIndex を -1 にすると親を持たないフレ??を ChildIndex で指定する )( 無かった場合は戻り値が-1 )
extern	const TCHAR *MV1GetFrameName( int MHandle, int FrameIndex ) ;											// 指定のフレ??の名前を取得する( エラ?の場合は戻り値が NULL )
extern	int			MV1GetFrameParent( int MHandle, int FrameIndex ) ;											// 指定のフレ??の親フレ??のインデックスを得る( 親がいない場合は -2 が返る )
extern	int			MV1GetFrameChildNum( int MHandle, int FrameIndex = -1 ) ;									// 指定のフレ??の子フレ??の数を取得する( FrameIndex を -1 にすると親を持たないフレ??の数が返ってくる )
extern	int			MV1GetFrameChild( int MHandle, int FrameIndex = -1 , int ChildIndex = 0 ) ;					// 指定のフレ??の子フレ??のフレ??インデックスを取得する( 番号指定版 )( FrameIndex を -1 にすると親を持たないフレ??を ChildIndex で指定する )( エラ?の場合は戻り値が-1 )
extern	VECTOR		MV1GetFramePosition( int MHandle, int FrameIndex ) ;										// 指定のフレ??の座標を取得する
extern	MATRIX		MV1GetFrameBaseLocalMatrix( int MHandle, int FrameIndex ) ;									// 指定のフレ??の初期状態での座標変換行列を取得する
extern	MATRIX		MV1GetFrameLocalMatrix( int MHandle, int FrameIndex ) ;										// 指定のフレ??の座標変換行列を取得する
extern	MATRIX		MV1GetFrameLocalWorldMatrix( int MHandle, int FrameIndex ) ;								// 指定のフレ??のロ?カル座標からワ?ルド座標に変換する行列を得る
extern	int			MV1SetFrameUserLocalMatrix( int MHandle, int FrameIndex, MATRIX Matrix ) ;					// 指定のフレ??の座標変換行列を設定する
extern	int			MV1ResetFrameUserLocalMatrix( int MHandle, int FrameIndex ) ;								// 指定のフレ??の座標変換行列をデフォルトに戻す
extern	VECTOR		MV1GetFrameMaxVertexLocalPosition( int MHandle, int FrameIndex ) ;							// 指定のフレ??が持つメッシュ頂?のロ?カル座標での最大値を得る
extern	VECTOR		MV1GetFrameMinVertexLocalPosition( int MHandle, int FrameIndex ) ;							// 指定のフレ??が持つメッシュ頂?のロ?カル座標での最小値を得る
extern	VECTOR		MV1GetFrameAvgVertexLocalPosition( int MHandle, int FrameIndex ) ;							// 指定のフレ??が持つメッシュ頂?のロ?カル座標での平均値を得る
extern	int			MV1GetFrameTriangleNum( int MHandle, int FrameIndex ) ;										// 指定のフレ??に含まれる?リゴンの数を取得する
extern	int			MV1GetFrameMeshNum( int MHandle, int FrameIndex ) ;											// 指定のフレ??が持つメッシュの数を取得する
extern	int			MV1GetFrameMesh( int MHandle, int FrameIndex, int Index ) ;									// 指定のフレ??が持つメッシュのメッシュインデックスを取得する
extern	int			MV1SetFrameVisible( int MHandle, int FrameIndex, int VisibleFlag ) ;						// 指定のフレ??の?示、非?示状態を変更する( TRUE:?示  FALSE:非?示 )
extern	int			MV1GetFrameVisible( int MHandle, int FrameIndex ) ;											// 指定のフレ??の?示、非?示状態を取得する( TRUE:?示  FALSE:非?示 )
extern	int			MV1SetFrameDifColorScale( int MHandle, int FrameIndex, COLOR_F Scale ) ;					// 指定のフレ??のディフュ?ズカラ?のスケ?ル値を設定する( デフォルト値は 1.0f )
extern	int			MV1SetFrameSpcColorScale( int MHandle, int FrameIndex, COLOR_F Scale ) ;					// 指定のフレ??のスペキュラカラ?のスケ?ル値を設定する( デフォルト値は 1.0f )
extern	int			MV1SetFrameEmiColorScale( int MHandle, int FrameIndex, COLOR_F Scale ) ;					// 指定のフレ??のエ?ッシブカラ?のスケ?ル値を設定する( デフォルト値は 1.0f )
extern	int			MV1SetFrameAmbColorScale( int MHandle, int FrameIndex, COLOR_F Scale ) ;					// 指定のフレ??のアンビエントカラ?のスケ?ル値を設定する( デフォルト値は 1.0f )
extern	COLOR_F		MV1GetFrameDifColorScale( int MHandle, int FrameIndex ) ;									// 指定のフレ??のディフュ?ズカラ?のスケ?ル値を取得する( デフォルト値は 1.0f )
extern	COLOR_F		MV1GetFrameSpcColorScale( int MHandle, int FrameIndex ) ;									// 指定のフレ??のスペキュラカラ?のスケ?ル値を取得する( デフォルト値は 1.0f )
extern	COLOR_F		MV1GetFrameEmiColorScale( int MHandle, int FrameIndex ) ;									// 指定のフレ??のエ?ッシブカラ?のスケ?ル値を取得する( デフォルト値は 1.0f )
extern	COLOR_F		MV1GetFrameAmbColorScale( int MHandle, int FrameIndex ) ;									// 指定のフレ??のアンビエントカラ?のスケ?ル値を取得する( デフォルト値は 1.0f )
extern	int			MV1GetFrameSemiTransState( int MHandle, int FrameIndex ) ;									// 指定のフレ??に半透明要素があるかどうかを取得する( 戻り値 TRUE:ある  FALSE:ない )
extern	int			MV1SetFrameOpacityRate( int MHandle, int FrameIndex, float Rate ) ;							// 指定のフレ??の不透明度を設定する( 不透明 1.0f ? 透明 0.0f )
extern	float		MV1GetFrameOpacityRate( int MHandle, int FrameIndex ) ;										// 指定のフレ??の不透明度を取得する( 不透明 1.0f ? 透明 0.0f )
extern	int			MV1SetFrameBaseVisible( int MHandle, int FrameIndex, int VisibleFlag ) ;					// 指定のフレ??の初期?示状態を設定する( TRUE:?示  FALSE:非?示 )
extern	int			MV1GetFrameBaseVisible( int MHandle, int FrameIndex ) ;										// 指定のフレ??の初期?示状態を取得する( TRUE:?示  FALSE:非?示 )
extern	int			MV1SetFrameTextureAddressTransform( int MHandle, int FrameIndex, float TransU, float TransV, float ScaleU, float ScaleV, float RotCenterU, float RotCenterV, float Rotate ) ;	// 指定のフレ??のテクス?ャ座標変換パラメ??を設定する
extern	int			MV1SetFrameTextureAddressTransformMatrix( int MHandle, int FrameIndex, MATRIX Matrix ) ;			// 指定のフレ??のテクス?ャ座標変換行列をセットする
extern	int			MV1ResetFrameTextureAddressTransform( int MHandle, int FrameIndex ) ;							// 指定のフレ??のテクス?ャ座標変換パラメ??をリセットする

// メッシュ関係
extern	int			MV1GetMeshNum( int MHandle ) ;																// モデルに含まれるメッシュの数を取得する
extern	int			MV1GetMeshMaterial( int MHandle, int MeshIndex ) ;											// 指定メッシュが使用している?テリアルのインデックスを取得する
extern	int			MV1GetMeshTriangleNum( int MHandle, int MeshIndex ) ;										// 指定メッシュに含まれる三角??リゴンの数を取得する
extern	int			MV1SetMeshVisible( int MHandle, int MeshIndex, int VisibleFlag ) ;							// 指定メッシュの?示、非?示状態を変更する( TRUE:?示  FALSE:非?示 )
extern	int			MV1GetMeshVisible( int MHandle, int MeshIndex ) ;											// 指定メッシュの?示、非?示状態を取得する( TRUE:?示  FALSE:非?示 )
extern	int			MV1SetMeshDifColorScale( int MHandle, int MeshIndex, COLOR_F Scale ) ;						// 指定のメッシュのディフュ?ズカラ?のスケ?ル値を設定する( デフォルト値は 1.0f )
extern	int			MV1SetMeshSpcColorScale( int MHandle, int MeshIndex, COLOR_F Scale ) ;						// 指定のメッシュのスペキュラカラ?のスケ?ル値を設定する( デフォルト値は 1.0f )
extern	int			MV1SetMeshEmiColorScale( int MHandle, int MeshIndex, COLOR_F Scale ) ;						// 指定のメッシュのエ?ッシブカラ?のスケ?ル値を設定する( デフォルト値は 1.0f )
extern	int			MV1SetMeshAmbColorScale( int MHandle, int MeshIndex, COLOR_F Scale ) ;						// 指定のメッシュのアンビエントカラ?のスケ?ル値を設定する( デフォルト値は 1.0f )
extern	COLOR_F		MV1GetMeshDifColorScale( int MHandle, int MeshIndex ) ;										// 指定のメッシュのディフュ?ズカラ?のスケ?ル値を取得する( デフォルト値は 1.0f )
extern	COLOR_F		MV1GetMeshSpcColorScale( int MHandle, int MeshIndex ) ;										// 指定のメッシュのスペキュラカラ?のスケ?ル値を取得する( デフォルト値は 1.0f )
extern	COLOR_F		MV1GetMeshEmiColorScale( int MHandle, int MeshIndex ) ;										// 指定のメッシュのエ?ッシブカラ?のスケ?ル値を取得する( デフォルト値は 1.0f )
extern	COLOR_F		MV1GetMeshAmbColorScale( int MHandle, int MeshIndex ) ;										// 指定のメッシュのアンビエントカラ?のスケ?ル値を取得する( デフォルト値は 1.0f )
extern	int			MV1SetMeshOpacityRate( int MHandle, int MeshIndex, float Rate ) ;							// 指定のメッシュの不透明度を設定する( 不透明 1.0f ? 透明 0.0f )
extern	float		MV1GetMeshOpacityRate( int MHandle, int MeshIndex ) ;										// 指定のメッシュの不透明度を取得する( 不透明 1.0f ? 透明 0.0f )
extern	int			MV1SetMeshDrawBlendMode( int MHandle, int MeshIndex, int BlendMode ) ;						// 指定のメッシュの?画ブレンドモ?ドを設定する( DX_BLENDMODE_ALPHA 等 )
extern	int			MV1SetMeshDrawBlendParam( int MHandle, int MeshIndex, int BlendParam ) ;					// 指定のメッシュの?画ブレンドパラメ??を設定する
extern	int			MV1GetMeshDrawBlendMode( int MHandle, int MeshIndex ) ;										// 指定のメッシュの?画ブレンドモ?ドを取得する( DX_BLENDMODE_ALPHA 等 )
extern	int			MV1GetMeshDrawBlendParam( int MHandle, int MeshIndex ) ;									// 指定のメッシュの?画ブレンドパラメ??を設定する
extern	int			MV1SetMeshBaseVisible( int MHandle, int MeshIndex, int VisibleFlag ) ;						// 指定のメッシュの初期?示状態を設定する( TRUE:?示  FALSE:非?示 )
extern	int			MV1GetMeshBaseVisible( int MHandle, int MeshIndex ) ;										// 指定のメッシュの初期?示状態を取得する( TRUE:?示  FALSE:非?示 )
extern	int			MV1SetMeshBackCulling( int MHandle, int MeshIndex, int CullingFlag ) ;						// 指定のメッシュのバックカリングを行うかどうかを設定する( DX_CULLING_LEFT 等 )
extern	int			MV1GetMeshBackCulling( int MHandle, int MeshIndex ) ;										// 指定のメッシュのバックカリングを行うかどうかを取得する( DX_CULLING_LEFT 等 )
extern	VECTOR		MV1GetMeshMaxPosition( int MHandle, int MeshIndex ) ;										// 指定のメッシュに含まれる?リゴンの最大ロ?カル座標を取得する
extern	VECTOR		MV1GetMeshMinPosition( int MHandle, int MeshIndex ) ;										// 指定のメッシュに含まれる?リゴンの最小ロ?カル座標を取得する
extern	int			MV1GetMeshTListNum( int MHandle, int MeshIndex ) ;											// 指定のメッシュに含まれるトライアングルリストの数を取得する
extern	int			MV1GetMeshTList( int MHandle, int MeshIndex, int Index ) ;									// 指定のメッシュに含まれるトライアングルリストのインデックスを取得する
extern	int			MV1GetMeshSemiTransState( int MHandle, int MeshIndex ) ;									// 指定のメッシュに半透明要素があるかどうかを取得する( 戻り値 TRUE:ある  FALSE:ない )
extern	int			MV1SetMeshUseVertDifColor( int MHandle, int MeshIndex, int UseFlag ) ;						// 指定のメッシュの頂?ディフュ?ズカラ?を?テリアルのディフュ?ズカラ?の代わりに使用するかどうかを設定する( TRUE:?テリアルカラ?の代わりに使用する  FALSE:?テリアルカラ?を使用する )
extern	int			MV1SetMeshUseVertSpcColor( int MHandle, int MeshIndex, int UseFlag ) ;						// 指定のメッシュの頂?スペキュラカラ?を?テリアルのスペキュラカラ?の代わりに使用するかどうかを設定する( TRUE:?テリアルカラ?の代わりに使用する  FALSE:?テリアルカラ?を使用する )
extern	int			MV1GetMeshUseVertDifColor( int MHandle, int MeshIndex ) ;									// 指定のメッシュの頂?ディフュ?ズカラ?を?テリアルのディフュ?ズカラ?の代わりに使用するかどうかの設定を取得する( 戻り値  TRUE:?テリアルカラ?の代わりに使用する  FALSE:?テリアルカラ?を使用する )
extern	int			MV1GetMeshUseVertSpcColor( int MHandle, int MeshIndex ) ;									// 指定のメッシュの頂?スペキュラカラ?を?テリアルのスペキュラカラ?の代わりに使用するかどうかの設定を取得する( 戻り値  TRUE:?テリアルカラ?の代わりに使用する  FALSE:?テリアルカラ?を使用する )

// トライアングルリスト関係
extern	int			MV1GetTriangleListNum( int MHandle ) ;														// トライアングルリストの数を取得する
extern	int			MV1GetTriangleListVertexType( int MHandle, int TListIndex ) ;								// 指定のトライアングルリストの頂?デ???イプを取得する( MV1_VERTEX_TYPE_NORMAL 等 )
extern	int			MV1GetTriangleListPolygonNum( int MHandle, int TListIndex ) ;								// 指定のトライアングルリストに含まれる?リゴンの数を取得する
extern	int			MV1GetTriangleListVertexNum( int MHandle, int TListIndex ) ;								// 指定のトライアングルリストに含まれる頂?デ??の数を取得する

// コリジョン関係
extern	int			MV1SetupCollInfo( int MHandle, int FrameIndex = -1 , int XDivNum = 32 , int YDivNum = 8 , int ZDivNum = 32 ) ;	// コリジョン情報を?築する
extern	int			MV1TerminateCollInfo( int MHandle, int FrameIndex = -1 ) ;									// コリジョン情報の後始末
extern	int			MV1RefreshCollInfo( int MHandle, int FrameIndex = -1 ) ;									// コリジョン情報を更新する
extern	MV1_COLL_RESULT_POLY     MV1CollCheck_Line( int MHandle, int FrameIndex, VECTOR PosStart, VECTOR PosEnd ) ; // 線とモデルの当たり判定
extern	MV1_COLL_RESULT_POLY_DIM MV1CollCheck_LineDim( int MHandle, int FrameIndex, VECTOR PosStart, VECTOR PosEnd ) ; // 線とモデルの当たり判定( 戻り値が MV1_COLL_RESULT_POLY_DIM )
extern	MV1_COLL_RESULT_POLY_DIM MV1CollCheck_Sphere( int MHandle, int FrameIndex, VECTOR CenterPos, float r ) ;	// 球とモデルの当たり判定
extern	MV1_COLL_RESULT_POLY_DIM MV1CollCheck_Capsule( int MHandle, int FrameIndex, VECTOR Pos1, VECTOR Pos2, float r ) ;	// カプセルとモデルの当たり判定
extern	MV1_COLL_RESULT_POLY     MV1CollCheck_GetResultPoly( MV1_COLL_RESULT_POLY_DIM ResultPolyDim, int PolyNo ) ;	// コリジョン結果?リゴン配列から指定番号の?リゴン情報を取得する
extern	int			MV1CollResultPolyDimTerminate( MV1_COLL_RESULT_POLY_DIM ResultPolyDim ) ;					// コリジョン結果?リゴン配列の後始末をする

// 参照用メッシュ関係
extern	int			MV1SetupReferenceMesh( int MHandle, int FrameIndex, int IsTransform ) ;						// 参照用メッシュのセットアップ
extern	int			MV1TerminateReferenceMesh( int MHandle, int FrameIndex, int IsTransform ) ;					// 参照用メッシュの後始末
extern	int			MV1RefreshReferenceMesh( int MHandle, int FrameIndex, int IsTransform ) ;					// 参照用メッシュの更新
extern	MV1_REF_POLYGONLIST	MV1GetReferenceMesh( int MHandle, int FrameIndex, int IsTransform ) ;				// 参照用メッシュを取得する

#endif

#define DX_FUNCTION_END

}

// ネ??スペ?ス DxLib を使用する ------------------------------------------------------
using namespace DxLib ;

// ＤＸライブラリ内部でのみ使用するヘッ?フ?イルのインクル?ド -------------------------

#ifdef __DX_MAKE
	#include "DxStatic.h"
#endif

#endif


