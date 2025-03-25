//leetcdoe-12: Integer to Roman

//Approach-1:
class Solution {
public:
    string intToRoman(int num) {
        string romanSymbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX","V", "IV", "I"};
        int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

        string ans = "";

        for(int i=0; i<13; i++){
            while(num >= values[i]){
                ans += romanSymbols[i];
                num -= values[i];
            }
        }

        return ans;
    }
};

//Approach-2:
class Solution {
public:
  string intToRoman(int num) {
	string ones[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
    string tens[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
    string hundreds[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
    string thousands[]={"","M","MM","MMM"};

		string ans= thousands[num/1000] + hundreds[(num%1000/100)] + tens[(num%100/10)] + ones[num%10];
		return ans;
	}
};