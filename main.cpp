/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
    Not every pointer can be converted.
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.

    You have to ask yourself if each pointer can be converted to a (const) reference.
    Think carefully when making your changes.

 2) revise the 'else' statement in main() that handles when `smaller` is a nullptr. 
 there is only one reason for `compare` to return nullptr. 
 Update this std::cout expression to specify why nullptr was returned.
 
 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */


#include <iostream>
#include <string>
struct T
{
    T(int v, const char* n) : value(v), name(n) {}   //1
    int value;//2
    std::string name;//3
};

struct F                                //4
{
    T* compare(T* a, T* b) //5
    {
        if(a != nullptr && b != nullptr)
        {
            if( a->value < b->value ) return a;
            if( a->value > b->value ) return b;
        }
        return nullptr;
    }
};

struct U
{
    float a { 0 }, b { 0 };
    float update(float* v)      //12
    {
        std::cout << "U's a value: " << a << std::endl;
        if( v == nullptr) 
        {
            std::cout << "error: v = nullptr" << std::endl;
            return 0.f;
        }
        a = *v;
        std::cout << "U's a updated value: " << a<< std::endl;
        while( std::abs(b - a) > 0.001f )
        {
            /*
             write something that makes the distance between that-><#name2#> and that-><#name1#> get smaller
             */
            b += .01f;
        }
        std::cout << "U's b updated value: " << b << std::endl;
        return a * b;
    }
};

struct S
{
    static float update(U* that, float* v)        //10
    {
        if (that == nullptr || v == nullptr)
        {
            std::cout << "Error: nullptr passed to update function" << std::endl;
            return 0.f;
        }
        std::cout << "U's a value: " << that->a << std::endl;
        that->a = *v;
        std::cout << "U's a updated value: " << that->a<< std::endl;
        while( std::abs(that->b - that->a) > 0.001f )
        {
            /*
             write something that makes the distance between that-><#name2#> and that-><#name1#> get smaller
             */
            that->b += .01f;
        }
        std::cout << "U's b updated value: " << that->b << std::endl;
        return that->a * that->b;
    }
};
        
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    T a( 32, "Ernie" );                                             //6
    T b( 35, "Bert" );                                             //6
    
    F f;                                            //7
    auto* smaller = f.compare( &a, &b );                              //8
    if(smaller != nullptr)
    {
        std::cout << "the smaller one is: " << smaller->name << std::endl; //9
    }
    else
    {
        if (a.value == b.value)
        {
            std::cout << "the values of " << a.name << " and " << b.name << " are equal" << std::endl;
        }
        else
        {
            std::cout << "Error, an invalid pointer was returned from the smaller function likely because an invalid pointer was supplied to it" << std::endl;
        }
    }
    
    U c;
    float updatedValue = 5.f;
    std::cout << "[static func] c's multiplied values: " << S::update(&c, &updatedValue ) << std::endl;                  //11
    
    U d;
    std::cout << "[member func] D's multiplied values: " << d.update( &updatedValue ) << std::endl;
}
