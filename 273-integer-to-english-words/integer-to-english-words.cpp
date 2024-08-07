class Solution {
public:
    string numberToWords(int num) {
        if(num == 0){
            return "Zero";
        }

        vector<string> ones = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        vector<string> thousands = {"", "Thousand", "Million", "Billion"};
        string res = "";
        int group = 0;
        int numb = num;
        while(numb > 0){
            if(numb%1000){
                string currRes = "";
                int sub = numb%1000;

                if(sub >= 100){
                    currRes += ones[sub/100] + " Hundred ";
                    sub = sub%100;
                }

                if(sub >= 20){
                    currRes += tens[sub/10] + " ";
                    sub = sub%10;
                }

                if(sub > 0){
                    currRes += ones[sub] + " "; 
                }

                currRes += thousands[group] + " ";
                res = currRes + res;
            }
            group++;
            numb /= 1000;
        }
        return res.substr(0, res.find_last_not_of(" ") + 1);
    }
};