class Solution {
public:
    string reverseVowels(string s) {
        int l = 0, h = s.size() - 1;
        while (l < h) {

            if ((s[l] == 'a' || s[l] == 'e' || s[l] == 'i' || s[l] == 'o' ||
                 s[l] == 'u' || s[l] == 'A' || s[l] == 'E' || s[l] == 'I' ||
                 s[l] == 'O' || s[l] == 'U') &&
                (s[h] == 'a' || s[h] == 'e' || s[h] == 'i' || s[h] == 'o' ||
                 s[h] == 'u' || s[h] == 'A' || s[h] == 'E' || s[h] == 'I' ||
                 s[h] == 'O' || s[h] == 'U')) {

                swap(s[l], s[h]);
                l++;
                h--;
            } else if (!(s[l] == 'a' || s[l] == 'e' || s[l] == 'i' ||
                         s[l] == 'o' || s[l] == 'u' || s[l] == 'A' ||
                         s[l] == 'E' || s[l] == 'I' || s[l] == 'O' ||
                         s[l] == 'U')) {

                l++;
            } else {

                h--;
            }
        }

        return s;
    }
};

// method 2

// bool isVowel(char ch){
//     ch = tolower(ch);
//     return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'';
// }

// int l=0, h=s.size()-1;

// while(l<h){
//     if(isVowel(s[l]) && isVowel(s[h])){

//         swap(s[l],s[h]);
//         l++;
//         h++;
//     }
//     else if(isVowel(s[l]) == 0)
//     {
//         l++;
//     }
//     else{
//         h--;
//     }

// }
// return s;


