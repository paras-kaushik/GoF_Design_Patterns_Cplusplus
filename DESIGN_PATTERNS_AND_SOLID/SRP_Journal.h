//
//  SRP_Journal.h
//  DESIGN_PATTERNS_AND_SOLID
//
//  Created by Paras Kaushik on 09/08/23.
//

#ifndef SRP_Journal_h
#define SRP_Journal_h
struct Journal{
  string title;
  vector<string> entries;
  explicit Journal(const string& title)
    : title{title}{}
    void add(const string& entry){
        static int count=1;
        entries.push_back(to_string(count++)+" : "+entry);
    }
};

struct PersistenceManager {
  static void save(const Journal& j, const string& filename)
  {
    ofstream ofs(filename);
      for (auto& s : j.entries){
          ofs << s << endl;
          cout<<s<<endl;
      }
  }
};

int main(){
  Journal journal{"Dear Diary"};
  journal.add("I ate a bug");
  journal.add("I cried today");

  PersistenceManager pm;
  pm.save(journal, "diary.txt");
}

#endif /* SRP_Journal_h */
