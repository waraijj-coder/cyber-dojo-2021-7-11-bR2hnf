#include "CppUTest/TestHarness.h"

extern "C"
{
#include "diamond.h"
}

TEST_GROUP(TestDiamond)
{
    void setup()
    {
    }

    void teardown()
    {
    }
};

/* Test some valid scenarios (min, max, mid cases) */ 
TEST(TestDiamond, testdiamonds_valid)
{
    // Test diamond A
    STRCMP_EQUAL("A\n", diamond('A'));
    
    // Test diamond B
    STRCMP_EQUAL(" A \n"
                 "B B\n"
                 " A \n", diamond('B'));

    // Test diamond C
    STRCMP_EQUAL("  A  \n"
                 " B B \n"
                 "C   C\n"
                 " B B \n"
                 "  A  \n", diamond('C'));
    
    // Test diamond d small caps
    STRCMP_EQUAL("   A   \n"
                 "  B B  \n"
                 " C   C \n"
                 "D     D\n"
                 " C   C \n"
                 "  B B  \n"
                 "   A   \n", diamond('d'));
    
    // I could create more tests or create a function to dynamically create a diamond to cover all cases
    // but I have opted not because of time and practicality (but can be improved and be done to ensure
    // all cases are covered. 

    // Test diamond z small caps
    STRCMP_EQUAL("                         A                         \n"
                 "                        B B                        \n"
                 "                       C   C                       \n"
                 "                      D     D                      \n"
                 "                     E       E                     \n"
                 "                    F         F                    \n"
                 "                   G           G                   \n"
                 "                  H             H                  \n"
                 "                 I               I                 \n"
                 "                J                 J                \n"
                 "               K                   K               \n"
                 "              L                     L              \n"
                 "             M                       M             \n"
                 "            N                         N            \n"
                 "           O                           O           \n"
                 "          P                             P          \n"
                 "         Q                               Q         \n"
                 "        R                                 R        \n"
                 "       S                                   S       \n"
                 "      T                                     T      \n"
                 "     U                                       U     \n"
                 "    V                                         V    \n"
                 "   W                                           W   \n"
                 "  X                                             X  \n"
                 " Y                                               Y \n"
                 "Z                                                 Z\n"
                 " Y                                               Y \n"
                 "  X                                             X  \n"
                 "   W                                           W   \n"
                 "    V                                         V    \n"
                 "     U                                       U     \n"
                 "      T                                     T      \n"
                 "       S                                   S       \n"
                 "        R                                 R        \n"
                 "         Q                               Q         \n"
                 "          P                             P          \n"
                 "           O                           O           \n"
                 "            N                         N            \n"
                 "             M                       M             \n"
                 "              L                     L              \n"
                 "               K                   K               \n"
                 "                J                 J                \n"
                 "                 I               I                 \n"
                 "                  H             H                  \n"
                 "                   G           G                   \n"
                 "                    F         F                    \n"
                 "                     E       E                     \n"
                 "                      D     D                      \n"
                 "                       C   C                       \n"
                 "                        B B                        \n"
                 "                         A                         \n", diamond('z'));  
}


/* Test some invalid scenarios */
TEST(TestDiamond, testdiamonds_invalid)
{
   // Test invalid input 0
   STRCMP_EQUAL("", diamond('0'));
 
   // Test invalid input 9
   STRCMP_EQUAL("", diamond('9'));

    // Test invalid input *
   STRCMP_EQUAL("", diamond('*'));
    
   // Test invalid input @
   STRCMP_EQUAL("", diamond('@'));
    
   // Test invalid input '^'
   STRCMP_EQUAL("", diamond('^'));    
}
