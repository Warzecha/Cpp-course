//
// Created by damian on 13.03.18.
//

#include <algorithm>
#include <stack>
#include <queue>
#include <iostream>
#include <ostream>
#include "SmartTree.h"

namespace datastructures
{
    std::unique_ptr<SmartTree> CreateLeaf(int value) {
        std::unique_ptr<SmartTree> tree = std::make_unique<SmartTree>();
        tree->value = value;
        return std::move(tree);
    }

    std::unique_ptr<SmartTree> InsertLeftChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> left_subtree) {
        tree->left = std::move(left_subtree);
        return std::move(tree);
    }

    std::unique_ptr<SmartTree>
    InsertRightChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> right_subtree) {
        tree->right = std::move(right_subtree);
        return std::move(tree);
    }

    void PrintTreeInOrder(const std::unique_ptr<SmartTree> &unique_ptr, std::ostream *out) {
        if(unique_ptr->left){
            PrintTreeInOrder(unique_ptr->left, out);
        }
        *out<<unique_ptr->value<<", ";
        if(unique_ptr->right){
            PrintTreeInOrder(unique_ptr->right, out);
        }

    }


    std::string HelpDump (const std::unique_ptr<SmartTree> &tree, std::string &str)
        ;

    std::string HelpDump2(const std::unique_ptr<SmartTree> &tree)
    {

        std::string str;
        return HelpDump(tree, str);

    }

    std::string HelpDump (const std::unique_ptr<SmartTree> &tree, std::string &str)
    {
        str += " [";

        if(!tree)
        {
            str+= "none";


        } else
        {
            str+= std::to_string(tree->value);

            str+=HelpDump2(tree->left);
            str+=HelpDump2(tree->right);



        }

        str+="]";

        return str;
    }

    std::string DumpTree(const std::unique_ptr<SmartTree> &tree) {
        if(!tree)
            return "";
        std::string str;
        str = HelpDump2(tree);
        str.erase(0, 1);
        return str;


    }

    std::unique_ptr<SmartTree> RestoreHelp(std::queue<std::string> &queueOfValues, std::queue<char > &queueOfBrackets, std::unique_ptr<SmartTree> &tree)
    {
//
//        if(queueOfBrackets.front() == ']')
//            return std::move(tree);

        if(!tree)
        {
            if(queueOfBrackets.front() == '[')
            {
                if(queueOfValues.front() == "none")
                {
                    return nullptr;
                } else
                {

                    int value = std::stoi(queueOfValues.front());
                    tree = CreateLeaf(value);

                    queueOfBrackets.pop();
                    queueOfValues.pop();
                }
            }

            return RestoreHelp(queueOfValues,queueOfBrackets, tree);
        } else
        {
            if(queueOfBrackets.front() == '[')
            {
                if(queueOfValues.front() != "none")
                {
                    int value = std::stoi(queueOfValues.front());
                    std::unique_ptr<SmartTree> child = CreateLeaf(value);
                    tree = InsertLeftChild(std::move(tree), std::move(child));
                    queueOfBrackets.pop();
                    queueOfValues.pop();
                    tree->left = RestoreHelp(queueOfValues, queueOfBrackets, tree->left);
                    queueOfBrackets.pop();
                }else
                {
                    queueOfBrackets.pop();
                    queueOfValues.pop();
                    queueOfBrackets.pop();
                }

            }
            if(queueOfBrackets.front() == '[')
            {
                if(queueOfValues.front() != "none")
                {
                    int value = std::stoi(queueOfValues.front());
                    std::unique_ptr<SmartTree> child = CreateLeaf(value);
                    tree = InsertRightChild(std::move(tree), std::move(child));
                    queueOfBrackets.pop();
                    queueOfValues.pop();
                    tree->right = RestoreHelp(queueOfValues, queueOfBrackets, tree->right);
                    queueOfBrackets.pop();
                }
            }else
            {
                queueOfBrackets.pop();
                queueOfValues.pop();
                queueOfBrackets.pop();
            }


            return std::move(tree);
        }



    }



    std::unique_ptr<SmartTree> RestoreTree(const std::string &str) {


        std::queue<std::string> queueOfValues;
        
        std::string str_copy = str;
        str_copy.erase(remove_if(str_copy.begin(), str_copy.end(), isspace), str_copy.end());
        str_copy.erase(std::remove(str_copy.begin(), str_copy.end(), ']'), str_copy.end());

        str_copy.erase(0,1);
        str_copy += '[';

        auto start = 0U;
        auto end = str_copy.find('[');
        while (end != std::string::npos)
        {
            std::string token = str_copy.substr(start, end - start);
            start = end + 1;
            end = str_copy.find('[', start);


            queueOfValues.push(token);
        }


        std::queue<char > queueOfBrackets;

        for(char c : str)
        {
            if(c == '[' || c == ']')
                queueOfBrackets.push(c);
        }


        std::unique_ptr<SmartTree> tree;
        tree = RestoreHelp(queueOfValues, queueOfBrackets, tree);

        return std::move(tree);
    }
}

