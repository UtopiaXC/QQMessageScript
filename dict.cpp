#include<string>
#include<list>

using namespace std;

class dicts {
public:
	list<string> list_anime;
	list<string> list_zuan;
	list<string> list_girls;
	list<string> list_agree;

	dicts() {
		list_anime.insert(list_anime.end(), "不是我抛弃了世界，而是世界抛弃了我");
		list_anime.insert(list_anime.end(), "不喜欢跟大人讲话，觉得这样会影响自己高贵的身份");
		list_anime.insert(list_anime.end(), "不拯救世界的日子，真是平淡啊，看着你们这些凡人能够享受和平的生活，还真是有些羡慕呢");
		list_anime.insert(list_anime.end(), "或许存在本身，就毫无意义可言");
		list_anime.insert(list_anime.end(), "或许压根就没有一个生物生来就是人类的伙伴，但就算来历不明，也都是值得尊重的同居者");
		list_anime.insert(list_anime.end(), "明明独自一人存在比什么都安全，为什么人类不能忍受独自一个人生活呢。");
		list_anime.insert(list_anime.end(), "能打败我的只有我自己");
		list_anime.insert(list_anime.end(), "情感什么的只是没有的杂草而已啊");
		list_anime.insert(list_anime.end(), "人类这种生物实在是太有趣、太吸引人、让人欲罢不能");
		list_anime.insert(list_anime.end(), "如果感情会成为障碍，那将它抹煞就可以了");
		list_anime.insert(list_anime.end(), "如果神拯救不了这个腐朽的世界，那就让我来毁掉它，顺便杀掉这个不中用的神");
		list_anime.insert(list_anime.end(), "若天压我，劈开那天，若地拘我，踏碎那地，我等生来自由身，谁敢高高在上");
		list_anime.insert(list_anime.end(), "世界上其实根本没有感同身受这回事，针不刺到别人身上，他们就不知道有多痛");
		list_anime.insert(list_anime.end(), "虽然我还是什么也做不了,但比起那些对现状毫不自知的愚蠢的家伙要好的多呢");
		list_anime.insert(list_anime.end(), "我对这个世界绝望过，但从未对自己绝望过");
		list_anime.insert(list_anime.end(), "我没有错，错的是世界");
		list_anime.insert(list_anime.end(), "只有弱者才喜欢扎堆，问题是绝大部分人都是弱者");
		list_anime.insert(list_anime.end(), "站在世界巅峰的人是不能拥有任何恐惧的");
		list_anime.insert(list_anime.end(), "愚蠢的人类怎么能理解我这样高贵和伟大的存在");
		list_anime.insert(list_anime.end(), "只有结果，这个世界上只有结果才能残留下来");

		list_zuan.insert(list_zuan.end(), "你妈生你那天，你爹一个都没来");
		list_zuan.insert(list_zuan.end(), "去拼多多拼个妈再来跟我说话");
		list_zuan.insert(list_zuan.end(), "团还在后边发呆，你在给你双亲吹唢呐？");
		list_zuan.insert(list_zuan.end(), "我只在乎你死去的妈");
		list_zuan.insert(list_zuan.end(), "几个妈呀说话这么嚣张");
		list_zuan.insert(list_zuan.end(), "以后给你妈打电话你先挂，别让你妈挂了");
		list_zuan.insert(list_zuan.end(), "你妈今晚八次爆炸，照亮整个台湾海峡，组成爱我中华");
		list_zuan.insert(list_zuan.end(), "跟你爹客气你妈呢？");
		list_zuan.insert(list_zuan.end(), "你看起来没有什么脑子，你妈一定去的很早，没来得及给你生个脑子");
		list_zuan.insert(list_zuan.end(), "常往天上看看，说不定你妈也在看你");
		list_zuan.insert(list_zuan.end(), "东边不亮西边亮，你爹啥样我啥样");
		list_zuan.insert(list_zuan.end(), "放妈过来吧");
		list_zuan.insert(list_zuan.end(), "听说你们家户口本只有一页");
		list_zuan.insert(list_zuan.end(), "我这就开微信摇一摇，看能不能摇到你妈");
		list_zuan.insert(list_zuan.end(), "人在祖安坐，马从天上来");
		list_zuan.insert(list_zuan.end(), "我的世界我做主，指手画脚妈入土");
		list_zuan.insert(list_zuan.end(), "你自言自语半天，你是跟你妈念往生咒还是再给你全家念大悲咒？");
		list_zuan.insert(list_zuan.end(), "一杯焦糖玛奇朵，有焦糖和奇朵，你妈呢？");
		list_zuan.insert(list_zuan.end(), "我是月黑风高偷你马棺材钱的爹");
		list_zuan.insert(list_zuan.end(), "你和你妈散步，你要先走，要不然你妈就走了");

		list_girls.insert(list_girls.end(), "今后也.请.多.多.指.教.喔? ~");
		list_girls.insert(list_girls.end(), "呐QAQ原来你已经变了啊，已经....不喜欢了呐");
		list_girls.insert(list_girls.end(), "阿诺，斯米马塞，造成了困扰红豆泥摩西加呆狗杂姨妈塞 T﹏T ");
		list_girls.insert(list_girls.end(), "呐呐，米娜桑");
		list_girls.insert(list_girls.end(), "啊啊……是~鲜~血~の~味~道~呐~~！");
		list_girls.insert(list_girls.end(), "呀帕里，我还是消失比较好呢…果咩捏，对你造成困扰了呢");
		list_girls.insert(list_girls.end(), "诶多诶多~「多洗忒」?为什么要「妄.图.抹.杀」这样的「自己」呢?");
		list_girls.insert(list_girls.end(), "唔噗噗~汝等「劣·等·生·物」......也配去「妄想」吗？");
		list_girls.insert(list_girls.end(), "诶多……看起来阁下对于「二·次·元」の理解、似·乎·满·是·谬·误·哦☆~");
		list_girls.insert(list_girls.end(), "啊嘞啊嘞QAQ？多洗忒……欧尼酱ww？呐、桥豆麻袋……已经「厌烦」吾辈了嘛？");
		list_girls.insert(list_girls.end(), "那群八嘎是不会懂的呀……关于「二次元の美好」~呐");
		list_girls.insert(list_girls.end(), "嘛……说到底，你们都只是污秽の「来自三次元的大人」吧？大人什么的、最·讨·厌·了");
		list_girls.insert(list_girls.end(), "fufufu——说到底、阁下已经「二·次·元·失·格」了吧？呐~");
		list_girls.insert(list_girls.end(), "米娜桑已经不喜欢了呀（紧咬嘴唇），得磨，米娜桑忘了当初吗（握紧小手）");
		list_girls.insert(list_girls.end(), "瓦大喜瓦，滋多滋多，滋多滋多（语气越来越用力了）滋多戴斯给！！！");
		list_girls.insert(list_girls.end(), "滋嘛叠磨瓦撕裂嘛赛！！！至死都不会瓦斯裂嘛斯（认真的表情）");
		list_girls.insert(list_girls.end(), "如果说吾の存在有意义的话、那一定是因为「二·次·元」吧☆？");
		list_girls.insert(list_girls.end(), "中二病的你」也好、「二次元的你」也好....「全部」daisuki~>w<呐~二次元民那赛高desuwa!");
		list_girls.insert(list_girls.end(), "诶多多~说着说着有些期待了呢~品尝「挚·爱·之·人」の「鲜血」什么的~！");
		list_girls.insert(list_girls.end(), "哇达西…死ki跌死，死ki死ki 带～死ki");


		list_agree.insert(list_agree.end(), "嗯嗯");
		list_agree.insert(list_agree.end(), "好");
		list_agree.insert(list_agree.end(), "就这样吧");
		list_agree.insert(list_agree.end(), "我没生气");
		list_agree.insert(list_agree.end(), "去洗澡了");
		list_agree.insert(list_agree.end(), "你是个好人");
		list_agree.insert(list_agree.end(), "还行");
		list_agree.insert(list_agree.end(), "一般般");
		list_agree.insert(list_agree.end(), "呵呵");
		list_agree.insert(list_agree.end(), "困了");
		list_agree.insert(list_agree.end(), "睡觉");
		list_agree.insert(list_agree.end(), "哈");
		list_agree.insert(list_agree.end(), "下次");
		list_agree.insert(list_agree.end(), "等有时间的");
		list_agree.insert(list_agree.end(), "没兴趣");
		list_agree.insert(list_agree.end(), "可以");
		list_agree.insert(list_agree.end(), "无聊");
		list_agree.insert(list_agree.end(), "哦");
		list_agree.insert(list_agree.end(), "吊");
		list_agree.insert(list_agree.end(), "很强");
		
		

	}
};
