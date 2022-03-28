// 부족한 금액 계산하기

using namespace std;

typedef long long ll;

long long solution(int price, int money, int count)
{    
    ll llprice = (ll) price;
    ll llmoney = (ll) money;
    ll llcount = (ll) count;
    
    ll sum = llprice * llcount * (1+llcount) / 2;
    
    return llmoney-sum < 0 ? sum - llmoney : 0;
}

/*

초항 price, 막항 price*count, 항 개수 count
-> (price + price*count) * count / 2
-> price * count + price * count * count / 2
-> price * count * (1 + count) / 2
범위 OK

*/