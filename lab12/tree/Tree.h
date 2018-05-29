//
// Created by damian on 29.05.18.
//

#ifndef JIMP_EXERCISES_TREE_H
#define JIMP_EXERCISES_TREE_H


#include <memory>

namespace tree
{
    template <typename T>





    class Tree {

    public:
        Tree(const T &element) : element(element) {}

        void Insert(const T &e) {

            if( e < element)
            {
                if(left == nullptr)
                {

                    left = std::make_unique<Tree>(e);
                }
                else
                {
                    left->Insert(e);
                }


            }
            else
            if(right == nullptr)
            {

                right = std::make_unique<Tree>(e);
            }
            else
            {
                right->Insert(e);
            }


        }

        bool Find(const T &e) {




            if(e == element)
            {
                return true;
            }
            else
            {
                if( e < element)
                {
                    if(left == nullptr)
                    {
                        return false;
                    }
                    else
                        left->Find(e);
                }
                else
                {
                    if(right == nullptr)
                    {
                        return false;
                    }
                    else
                        right->Find(e);
                }

            }


            return false;
        }

        size_t Depth() const {

            size_t left_depth = 0;
            size_t right_depth = 0;


            if(left)
                left_depth = left->Depth();

            if(right)
                right_depth = right->Depth();


            return std::max(left_depth, right_depth) + 1;
        }

        size_t Size() const{
            size_t left_size = 0;
            size_t right_size = 0;


            if(left)
                left_size = left->Size();

            if(right)
                right_size = right->Size();


            return left_size + right_size + 1;
        }

        T Value() const {
            return element;
        }


    private:

        T element;
        std::unique_ptr<Tree> left = nullptr;
        std::unique_ptr<Tree> right = nullptr;


    };




}


#endif //JIMP_EXERCISES_TREE_H
