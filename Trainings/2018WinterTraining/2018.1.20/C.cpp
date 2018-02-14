/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-01-20	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const long long mod=1000000006LL;
const long long G=500000003LL;
const int MAXN=100050;
long long lg[1050]={-1,0,500000002,614726078,1000000004,957229801,114726074,615068152,500000000,229452150,457229797,478447576,614726076,49793149,115068148,571955873,1000000002,590946905,729452152,325946403,957229799,229794224,978447578,960421893,114726072,914459596,549793151,844178228,615068150,312322140,71955869,508832294,499999998,93173648,90946901,572297947,229452148,596031423,825946405,664519227,457229795,298734537,729794226,607125352,478447574,186681945,460421889,956100609,614726074,230136298,414459592,205672977,49793147,129261495,344178224,435677371,115068146,940672481,812322142,268424538,571955871,568491226,8832290,844520302,1000000000,7022944,593173650,194010567,590946903,575147965,72297943,977876323,729452150,875379711,96031419,529185668,325946401,93515722,164519223,807554834,957229797,458904300,798734539,703422044,229794222,548176700,107125348,927048218,978447576,419856427,686681947,664861301,960421891,123558366,456100605,283176198,114726070,206156291,730136300,707899726,914459594,945456720,705672979,448080934,549793149,187024019,629261497,613799885,844178226,197607444,935677373,210757495,615068148,110145311,440672477,917651688,312322138,279245299,768424540,206015051,71955867,956895152,68491222,913460615,508832292,871689391,344520298,618701234,499999996,221851424,507022946,370284462,93173646,941014555,694010569,801408023,90946899,104980966,75147961,647499301,572297945,570826681,477876319,528240725,229452146,269551935,375379707,844862376,596031421,142037041,29185664,45508837,825946403,820399055,593515724,466062089,664519225,581420851,307554830,743987573,457229793,575490039,958904302,538598711,298734535,50403443,203422040,260264822,729794224,99586298,48176696,555398553,607125350,925348946,427048214,529527742,478447572,883150616,919856429,191189113,186681943,7397358,164861297,183217298,460421887,553261218,623558368,69394475,956100607,459246374,783176200,833573099,614726072,561791838,706156293,621749022,230136296,488226142,207899722,654387383,414459590,808736645,445456716,927390292,205672975,255964332,948080936,189874037,49793145,804393979,687024021,739288758,129261493,592602395,113799881,564355147,344178222,123900440,697607446,490105783,435677369,640740054,710757497,888471990,115068144,143911740,610145313,907908611,940672479,645038591,417651684,708241800,812322140,665356697,779245301,913330404,268424536,422280906,706015053,635777886,571955869,611313034,456895148,73630372,568491224,187366093,413460611,375739552,8832288,318148116,371689387,505524091,844520300,438869463,118701230,162902772,999999998,401514796,721851426,211099569,7022942,541774290,870284464,888596659,593173648,86491290,441014551,34582499,194010565,726458011,301408019,495119852,590946901,279587373,604980968,392907166,575147963,864727822,147499297,738284444,72297941,264306336,70826677,552945361,977876321,897902276,28240721,913802689,729452148,181893804,769551937,820882369,875379709,727468318,344862372,225654333,96031417,322625798,642037043,10215036,529185666,222193498,545508839,560182792,325946399,525721021,320399051,413276805,93515720,62807006,966062091,560052398,164519221,514706737,81420847,801750097,807554832,901440584,243987569,790769716,957229795,228525957,75490035,916893308,458904298,964252745,38598707,812333522,798734537,571168755,550403445,160505649,703422042,825483573,760264824,151240362,229794220,199996964,599586300,724871389,548176698,987279870,55398549,845204450,107125346,532377760,425348942,399619320,927048216,485736499,29527738,893971377,978447574,326976109,383150612,935106118,419856425,820741129,691189115,901783328,686681945,651892806,507397360,571621224,664861299,832609506,683217300,778065571,960421889,528186687,53261214,744329647,123558364,51304497,569394477,486415463,456100603,362115289,959246376,99475363,283176196,233427306,333573095,123031587,114726068,50745517,61791834,836577502,206156289,772056022,121749018,551368792,730136298,985010540,988226144,764784629,707899724,589529845,154387379,555740627,914459592,946638804,308736641,558625443,945456718,416134095,427390288,74478993,705672977,253964374,755964334,719707044,448080932,883492690,689874039,660651839,549793147,262225373,304393975,294817807,187024017,846540049,239288754,185552753,629261495,505406495,92602391,183559372,613799883,142966797,64355143,930304550,844178224,295806678,623900442,884278013,197607442,286368290,990105785,683515644,935677371,459588448,140740050,276047844,210757493,377086222,388471986,756763119,615068146,284611716,643911742,777182113,110145309,660234915,407908607,622091096,440672475,878625984,145038587,435125127,917651686,32150213,208241796,107205666,312322136,80788161,165356693,527494888,279245297,809078719,413330400,196146923,768424538,85572922,922280908,240405993,206015049,358713645,135777882,20038242,71955865,645824572,111313030,190216111,956895150,163386086,573630374,617152497,68491220,153324783,687366095,722794679,913460613,903269045,875739554,665129521,508832290,592944469,818148118,187479774,871689389,874990900,5524087,992783415,344520296,902686515,938869465,714312376,618701232,421461795,662902774,490447857,499999994,170124625,901514798,405310729,221851422,434548179,711099571,540075018,507022944,350074926,41774286,363011875,370284460,144253814,388596655,99779193,93173644,920843780,586491292,497876688,941014553,348527686,534582501,571029680,694010567,805915191,226458007,708583874,801408021,534097461,995119854,622123436,90946897,154837239,779587375,921124882,104980964,797943376,892907168,638268543,75147959,422622980,364727818,167987290,647499299,988847548,238284440,656918501,572297943,684120553,764306338,465599750,570826679,67375106,52945357,73972446,477876317,299980423,397902272,150689408,528240723,448299171,413802685,874881483,229452144,970931906,681893806,176517910,269551933,318490190,320882365,607709071,375379705,236475094,227468314,966660708,844862374,834778697,725654335,102952214,596031419,197281257,822625800,163244846,142037039,269113455,510215038,720523072,29185662,798180388,722193500,423462717,45508835,914124947,60182788,571584383,825946401,542116364,25721017,5893752,820399053,184260040,913276807,870690410,593515722,390020772,562807008,633435728,466062087,804600115,60052394,34924573,664519223,828919186,14706733,419120051,581420849,186978322,301750093,90728007,307554828,354014830,401440580,575931029,743987571,279929447,290769712,207328467,457229791,496422081,728525959,261072436,575490037,179081219,416893304,352237531,958904300,746872114,464252741,738626518,538598709,36559788,312333518,327514257,298734533,104831855,71168751,557030104,50403441,481339061,660505651,255466126,203422038,898244350,325483569,272744027,260264820,503198062,651240364,46938796,729794222,965519112,699996966,758637818,99586296,515491902,224871385,821224443,48176694,522634683,487279866,929477824,555398551,62210761,345204446,259764663,607125348,179054644,32377756,951988467,925348944,322967872,899619322,604729096,427048212,889681442,985736501,280082769,529527740,684903006,393971373,921977826,478447570,528056476,826976111,560524866,883150614,9044991,435106114,37006978,919856427,469254181,320741125,485470520,191189111,250503958,401783324,911127337,186681941,63149080,151892802,226039106,7397356,226781730,71621220,184315749,164861295,688356450,332609502,198072251,183217296,480724644,278065567,802092171,460421885,672458143,28186683,459021661,553261216,990465630,244329643,401401931,623558366,99266836,551304499,932874194,69394473,228868031,986415465,822704142,956100605,120250163,862115291,2738632,459246372,203485236,599475365,53595535,783176198,363370948,733427308,812675596,833573097,777628850,623031589,318217687,614726070,419088715,550745519,16240868,561791836,702167272,336577498,423291884,706156291,825825647,272056018,624680940,621749020,456323893,51368788,156500362,230136294,538650646,485010536,632391667,488226140,503322731,264784625,725213463,207899720,618284375,89529841,701217368,654387381,429395339,55740623,547047508,414459588,649308577,446638800,353827281,808736643,532719834,58625439,341184083,445456714,135994071,916134097,249508378,927390290,109845924,574478995,495828506,205672973,933071755,753964376,894313451,255964330,405923293,219707040,697384311,948080934,7633238,383492686,532201093,189874035,705296338,160651835,479453894,49793143,821083203,762225375,217494617,804393977,353010516,794817809,277370540,687024019,624644280,346540045,879032414,739288756,56816093,685552755,571963298,129261491,167671433,5406491,556453310,592602393,728096860,683559374,512628348,113799879,110026193,642966799,224494694,564355145,528528761,430304546,582140627,344178220,882578741,795806680,796619882,123900438,286002404,384278009,243803716,697607444,435608441,786368292,486757537,490105781,740850084,183515640,342194390,435677367,666813353,959588450,168875241,640740052,840380411,776047846,866254097,710757495,233769380,877086224,937351876,888471988,282047006,256763115,148418908,115068142,624941114,784611718,821154434,143911738,720208400,277182109,836919576,610145311,964627159,160234911,281628116,907908609,174908864,122091092,712511188,940672477,181869614,378625980,140447093,645038589,985352614,935125129,790294067,417651682,28002877,532150215,27669466,708241798,510491013,607205668,677533084,812322138,317980076,580788163,556082701,665356695,174778470,27494884,26624270,779245299,909308079,309078715,129432809,913330402,468425760,696146925,259156424,268424534,416476169,585572924,659151896,422280904,925172860,740405995,516166656,706015051,291046387,858713647,790802894,635777884,405495788,520038244,720049118,571955867,17664582,145824568,843252035,611313032,519021633,690216113,574083465,456895146,531619380,663386088,77326599,73630370,262567447,117152493,578978817,568491222,443748952,653324785,898304003,187366091,427059594,222794675,873924170,413460609,445455937,403269041,185894827,375739550,567547239,165129517,640979012,8832286,775231727,92944465,611617178,318148114,582063268,687479776,440209645,371689385};
int T_T,n,q,num[MAXN];
int L[MAXN<<2],R[MAXN<<2];
long long data[MAXN<<2],tag[MAXN<<2][2];// 0 add, 1 multi
long long pOw1(long long a,long long n)
{
	long long ans;
	for(ans=1;n;n>>=1,a=a*a%mod)
		if(n&1)
			ans=ans*a%mod;
	return ans;
}
void down(int root)
{
	if(L[root]==R[root]||(tag[root][0]==0&&tag[root][1]==1)) return;
	if(tag[root][1])
	{
		data[root<<1]=data[root<<1]*tag[root][1]%mod;
		tag[root<<1][1]=(tag[root<<1][1]*tag[root][1])%mod;
		tag[root<<1][0]=tag[root<<1][0]*tag[root][1]%mod;
		data[root<<1|1]=data[root<<1|1]*tag[root][1]%mod;
		tag[root<<1|1][1]=(tag[root<<1|1][1]*tag[root][1])%mod;
		tag[root<<1|1][0]=tag[root<<1|1][0]*tag[root][1]%mod;
		tag[root][1]=1;
	}
	if(tag[root][0])
	{
		data[root<<1]=(data[root<<1]+tag[root][0]*(R[root<<1]-L[root<<1]+1)%mod)%mod;
		tag[root<<1][0]=(tag[root<<1][0]+tag[root][0])%mod;
		data[root<<1|1]=(data[root<<1|1]+tag[root][0]*(R[root<<1|1]-L[root<<1|1]+1)%mod)%mod;
		tag[root<<1|1][0]=(tag[root<<1|1][0]+tag[root][0])%mod;
		tag[root][0]=0;
	}
	return;
}
void build(int root,int l,int r)
{
	L[root]=l; R[root]=r;
	tag[root][0]=data[root]=0;
	tag[root][1]=1;
	if(l==r)
	{
		data[root]=lg[num[l]];
		return;
	}
	int mid=(l+r)>>1;
	build(root<<1,l,mid);
	build(root<<1|1,mid+1,r);
	data[root]=(data[root<<1]+data[root<<1|1])%mod;
	return;
}
void add(int root,int l,int r,long long x)
{
	down(root);
	if(l<=L[root]&&R[root]<=r)
	{
		data[root]=(data[root]+x*(R[root]-L[root]+1)%mod)%mod;
		tag[root][0]+=x;
		return;
	}
	int mid=(L[root]+R[root])>>1;
	if(l<=mid) add(root<<1,l,r,x);
	if(mid<r) add(root<<1|1,l,r,x);
	data[root]=(data[root<<1]+data[root<<1|1])%mod;
	return;
}
void multi(int root,int l,int r,long long k)
{
	down(root);
	if(l<=L[root]&&R[root]<=r)
	{
		data[root]=data[root]*k%mod;
		tag[root][1]=(tag[root][1]*k)%mod;
		tag[root][0]=(tag[root][0]*k)%mod;
		return;
	}
	int mid=(L[root]+R[root])>>1;
	if(l<=mid) multi(root<<1,l,r,k);
	if(mid<r) multi(root<<1|1,l,r,k);
	data[root]=(data[root<<1]+data[root<<1|1])%mod;
	return;
}
long long query(int root,int l,int r)
{
	if(l<=L[root]&&R[root]<=r) return data[root];
	down(root);
	int mid=(L[root]+R[root])>>1;
	long long ans=0;
	if(l<=mid) ans=(ans+query(root<<1,l,r))%mod;
	if(mid<r) ans=(ans+query(root<<1|1,l,r))%mod;
	return ans;
}
long long pOw2(long long a,long long n)
{
	long long ans;
	for(ans=1;n;n>>=1,a=a*a%(mod+1))
		if(n&1)
			ans=ans*a%(mod+1);
	return ans;
}
template<typename Ty>
void read1n(Ty &x)
{
	char ch=getchar();
	while(ch<'0'||'9'<ch) ch=getchar();
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	int op,l,r;
	long long x;
	read1n(T_T);
	while(T_T-->0)
	{
		read1n(n); read1n(q);
		for(int i=1;i<=n;i++)
			read1n(num[i]);
		build(1,1,n);
		while(q-->0)
		{
			read1n(op);
			read1n(l);
			read1n(r);
			switch(op)
			{
				case 1:
					read1n(x);
					add(1,l,r,lg[x]);
					break;
				case 2:
					read1n(x);
					multi(1,l,r,x);
					break;
				case 3:
					printf("%lld\n",pOw2(G,query(1,l,r)));
					break;
				default:
					break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

