#include "header.h"

struct FileObject
{
    string name;
    bool isDir;
    string content;
    map<string, FileObject*> children;
};

class FileSystem {
private:
    FileObject* root;
public:
    FileSystem() {
        root = new FileObject();
        root->isDir = true;
    }

    vector<string> parsePath(const string& path)
    {
        vector<string> res;
        int lastSlashIdx = -1;
        for(int i = 0, n = path.size(); i < n; ++i)
        {
            if(path[i] == '/')
            {
                if(lastSlashIdx != -1)
                {
                    res.push_back(path.substr(lastSlashIdx + 1, i - lastSlashIdx - 1));
                }

                lastSlashIdx = i;
            }
            else if(i == n - 1 && path[i] != '/')
            {
                res.push_back(path.substr(lastSlashIdx + 1));
            }
        }
        return res;
    }

    vector<string> ls(string path) {
        vector<string> res;
        const auto& v = parsePath(path);
        FileObject* p = root;
        for(const auto& name : v)
        {
            p = p->children[name];
        }

        if(p->isDir)
        {
            for(const auto& child : p->children)
                res.push_back(child.first);
        }
        else
        {
            res.push_back(p->name);
        }
        return res;
    }

    void mkdir(string path) {
        const auto& v = parsePath(path);
        FileObject* p = root;
        for(const auto& name : v)
        {
            if(p->children.count(name))
            {
                p = p->children[name];
            }
            else
            {
                FileObject* f = new FileObject();
                f->name = name;
                f->isDir = true;
                p->children[name] = f;
                p = p->children[name];
            }
        }
    }

    void addContentToFile(string filePath, string content) {
        const auto& v = parsePath(filePath);
        FileObject* p = root;
        for(const auto& name : v)
        {
            if(p->children.count(name))
            {
                p = p->children[name];
            }
            else
            {
                p->children[name] = new FileObject();
                p = p->children[name];
                p->name = v.back();
                p->isDir = false;
            }
        }

        p->content += content;
    }

    string readContentFromFile(string filePath) {
        const auto& v = parsePath(filePath);
        FileObject* p = root;
        for(const auto& name : v)
        {
            p = p->children[name];
        }
        return p->content;
    }
};


int main()
{
    //Solution s;
}
