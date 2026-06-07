class Solution {
  public:
    string profession(int level, int pos) {
        // Base case: The root of the family tree is always an Engineer
        if (pos == 1) {
            return "Engineer";
        }
        
        // Find the profession of the parent node
        string parentProfession = profession(level - 1, (pos + 1) / 2);
        
        // If pos is odd, it's the 1st child -> same profession as parent
        if (pos % 2 != 0) {
            return parentProfession;
        } 
        // If pos is even, it's the 2nd child -> opposite profession of parent
        else {
            return (parentProfession == "Engineer") ? "Doctor" : "Engineer";
        }
    }
};
