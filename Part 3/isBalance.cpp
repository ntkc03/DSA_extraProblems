/*
    - Bai
*/
string isBalanced(string s) {
    if(s.size() % 2 != 0) return "NO";
    int left = 0, right = 0;
    while(left < s.size() - 1 && right < s.size())
    {
        while(left < s.size() - 1 && (s[left + 1] == '(' || s[left + 1] == '{' || s[left + 1] == '['))
        {
            left++;
        }
        if(left >= s.size() - 1) return "NO";
        right = left + 1;
        if((s[left] == '(' && s[right] == ')') || (s[left] == '{' && s[right] == '}') || (s[left] == '[' && s[right] == ']')){
            s.erase(s.begin() + left, s.begin() + left + 2);
            if(left > 0) left--;
            right = left;
        }
        else return "NO";
        //cout << s << endl;
    }
    return "YES";
}
