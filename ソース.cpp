#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std; 

string name_conversion(int symbolArcana)
{
	//大アルカナの番号に応じたカード名をstring型で渡す
	if (symbolArcana >= 22) {
		return "error";
	}

	vector<string> arcanaName(22);
	arcanaName = { 
		          "愚者", "魔術師", "女教皇", "女帝", "皇帝", "法王", 
				  "恋人", "戦車", "力", "隠者", "運命の輪", "正義", 
				  "吊るし人", "死神", "節制", "悪魔", "塔", "星", 
				  "月", "太陽", "審判", "世界" 
	             };
	
	return arcanaName.at(symbolArcana);
}

string position_conversion(int symbolPosition)
{
	if (symbolPosition == 0) {
		return "正位置";
	}
	else if (symbolPosition == 1) {
		return "逆位置";
	}
	else {
		return "error";
	}
}

string symbol_output(int symbolArcana, int symbolPosition)
{
	if (symbolArcana >= 22 || symbolPosition >= 2) {
		return "error";
	}

	vector<vector<string>> vecSymbol(2, vector<string>(22));
	vecSymbol = { {"旅立ち、自由人", "独創性　技術力　転機",
		          "思慮深さ　努力家", "繁栄　豊かさ　収穫", 
		          "優れた指導力　責任感", "善良　堅実", 
		          "祝福された愛　遊び", "コントロール　勝利　移動", 
	          	  "穏やかな強さ　積極性", "思慮分別　良き相談相手", 
		          "物事の好転　運命的な出来事", "バランスの取れた判断　常識的", 
		          "自己犠牲愛", "終止　悪い変化", 
		          "適応　自重", "妄想にとらわれる　誘惑", 
		          "急なトラブル　損失", "希望　順調", 
		          "不安定　嘘", "成功　希望が叶う", 
		          "復活　解放　変革", "完成　勝利"
		         },
		         {"計画性の無さ、非協調的", "方向転換の時期　経験不足", 
	              "あさはかさ　気難しさ", "不安定な愛　停滞", 
	              "弱さ　優柔不断", "行き過ぎた行動　信仰心の無さ", 
	              "悩み　三角関係", "報われない勝利　独占欲", 
		          "誘惑に負ける　無気力", "不信　人付き合いが苦手", 
		          "良いものが悪くなる　宿命から逃れられない", "不正　偏る", 
		          "無意味な奉仕　拘束", "新たな出発　良い変化", 
		          "不毛　忍耐力の無さ", "更正　目が覚める", 
		          "九死に一生を得る", "悲観的　大きすぎる理想", 
		          "嘘に気づく　小さくてすむ危険な出来事", "下降　望みが叶わない", 
		          "こだわる　遅延", "頓挫　挫折"
	             },
	            };

	return vecSymbol.at(symbolPosition).at(symbolArcana);
}

void play(int majorArcanaNum, int uprightReverseNum) {
	cout << majorArcanaNum << "番、";
	cout << name_conversion(majorArcanaNum) << "の";
	cout << position_conversion(uprightReverseNum) << "を引きました。" << endl;

	cout << symbol_output(majorArcanaNum, uprightReverseNum) << " の象徴です。" << endl;
}

int main()
{
	srand(time(NULL));

	int firstMajorArcanaNum = rand() % 22; //大アルカナの番号
	int firstUprightReverseNum = rand() % 2; //0が正位置、1が逆位置

	cout << "タロット占いを始めましょう。" << endl;
	cout << "まず過去を占います。";
	cout << "Enterキーを押してください。" << endl;

	getchar();

	play(firstMajorArcanaNum, firstUprightReverseNum); //過去を出力


	cout << "次に現在を占います。";
	cout << "Enterキーを押してください。" << endl;

	getchar();

	int secondMajorArcanaNum = firstMajorArcanaNum; //1回目のrandを確実に行う

	while (1 == 1) {
		if (firstMajorArcanaNum == secondMajorArcanaNum) {
			secondMajorArcanaNum = rand() % 22; //大アルカナ
		}
		else {
			break; //一回目と違う大アルカナを引いたら終了
		}
	}

	int secondUprightReverseNum = rand() % 2; //0が正位置、1が逆位置

	play(secondMajorArcanaNum, secondUprightReverseNum); //現在を出力


	cout << "最後に未来を占います。";
	cout << "Enterキーを押してください。" << endl;

	getchar();

	int finalMajorArcanaNum = firstMajorArcanaNum;

	while (1 == 1) {
		if (firstMajorArcanaNum == finalMajorArcanaNum || secondMajorArcanaNum == finalMajorArcanaNum) {
			finalMajorArcanaNum = rand() % 22; //大アルカナ
		}
		else {
			break; //1,2回目と違う大アルカナを引いたら終了
		}
	}

	int finalUprightReverseNum = rand() % 2; //0が正位置、1が逆位置

	play(finalMajorArcanaNum, finalUprightReverseNum); //未来を出力


	cout << "これでタロット占いを終わります。よい一日を。" << endl;
}