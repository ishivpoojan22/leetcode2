class Solution {
public:
    string reverseOnlyLetters(string s) {

        int l = 0, h = s.size() - 1;
        while (l < h) {
            if (isalpha(s[l]) && isalpha(s[h])) {

                swap(s[l], s[h]);
                l++, h--;
            } else if (!isalpha(s[l])) {
                l++;
            } else {

                // s[h] -->non-alpha
                h--;
            }
        }
        return s;
    }
};    

    // method 2 acoding to ascii value
    // while(l<h){
    //     if(((s[l]>=97 && s[l]<=122) || (s[l]>=65 && s[l]<=90) && 
    //     ((s[h]>=97 && s[h]<=122) || (s[h]>=65 && s[h]<=90))){

    //         swap(s[l],s[h]);
    //         l++;
    //         h--;
    //     }
    //     else if(!((s[l] >= 97 && s[l] <= 122) || (s[l] >= 65 && s[l] <= 90))){
    //         l++;
    //     }
    //     else{
    //         s[h]-->not aplha
    //         h--;
    //     }

    // }
    // return s;