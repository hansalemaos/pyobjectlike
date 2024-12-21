# Some basic PyObject functionality (mixed data types) for C++

## How to use it 

```cpp
#include "pyobjectlike.h"
int main()
{
    static constexpr std::string_view endline{"\n------------------------------------------------------------------\n"};
    PyObjectLike object_001{"Hello, world0!"};
    PyObjectLike object_002{3.14};
    PyObjectLike object_003{true};
    PyObjectLike object_004{5};
    int8_t con_to_object_005{'A'};
    PyObjectLike object_005{con_to_object_005};
    int16_t con_to_object_006{400};
    PyObjectLike object_006{con_to_object_006};
    int32_t con_to_object_007{-33333};
    PyObjectLike object_007{con_to_object_007};
    int64_t con_to_object_008{43325434453};
    PyObjectLike object_008{con_to_object_008};
    uint8_t con_to_object_009{255};
    PyObjectLike object_009{con_to_object_009};
    uint16_t con_to_object_010{65535};
    PyObjectLike object_010{con_to_object_010};
    uint32_t con_to_object_011{4294967295};
    PyObjectLike object_011{con_to_object_011};
    uint64_t con_to_object_012{18446744073709551615};
    PyObjectLike object_012{con_to_object_012};
    const char *con_to_object_013{"Hello, world1!"};
    PyObjectLike object_013{con_to_object_013};
    std::string con_to_object_014{"Hello, world2!"};
    PyObjectLike object_014{con_to_object_014};
    const std::string_view con_to_object_015{"Hello, world3!"};
    PyObjectLike object_015{con_to_object_015};
    std::cout << object_001 << endline;
    std::cout << object_002 << endline;
    std::cout << object_003 << endline;
    std::cout << object_004 << endline;
    std::cout << object_005 << endline;
    std::cout << object_006 << endline;
    std::cout << object_007 << endline;
    std::cout << object_008 << endline;
    std::cout << object_009 << endline;
    std::cout << object_010 << endline;
    std::cout << object_011 << endline;
    std::cout << object_012 << endline;
    std::cout << object_013 << endline;
    std::cout << object_014 << endline;
    std::cout << object_015 << endline;
    std::unordered_map<PyObjectLike, PyObjectLike> umap0{
        {object_001, object_002}, {object_003, object_004}, {object_005, object_006}, {object_007, object_008},
        {object_009, object_010}, {object_011, object_012}, {object_013, object_014}, {object_015, object_002}};
    std::map<PyObjectLike, PyObjectLike> map0{
        {object_001, object_002}, {object_003, object_004}, {object_005, object_006}, {object_007, object_008},
        {object_009, object_010}, {object_011, object_012}, {object_013, object_014}, {object_015, object_002}};

    // duplicates are dropped
    std::set<PyObjectLike> set0{object_001, object_002, object_003, object_004, object_005, object_006,
                                object_007, object_008, object_009, object_010, object_011, object_012,
                                object_013, object_014, object_015, object_001, object_002, object_003,
                                object_004, object_005, object_006, object_007, object_008, object_009,
                                object_010, object_011, object_012, object_013, object_014, object_015};

    // duplicates are dropped
    std::unordered_set<PyObjectLike> uset0{object_001, object_002, object_003, object_004, object_005, object_006,
                                           object_007, object_008, object_009, object_010, object_011, object_012,
                                           object_013, object_014, object_015, object_001, object_002, object_003,
                                           object_004, object_005, object_006, object_007, object_008, object_009,
                                           object_010, object_011, object_012, object_013, object_014, object_015};

    std::list<PyObjectLike> list0{object_001, object_002, object_003, object_004, object_005,
                                  object_006, object_007, object_008, object_009, object_010,
                                  object_011, object_012, object_013, object_014, object_015};
    std::forward_list<PyObjectLike> f_list0{object_001, object_002, object_003, object_004, object_005,
                                            object_006, object_007, object_008, object_009, object_010,
                                            object_011, object_012, object_013, object_014, object_015};

    std::array<PyObjectLike, 5> arr0{object_001, object_002, object_003, object_004, object_005};
    std::vector<PyObjectLike> vec0{object_001, object_002, object_003, object_004, object_005};
    std::cout << umap0 << endline;
    std::cout << map0 << endline;
    std::cout << set0 << endline;
    std::cout << uset0 << endline;
    std::cout << list0 << endline;
    std::cout << f_list0 << endline;
    std::cout << arr0 << endline;
    std::cout << vec0 << endline;

    const std::string_view strconcatsv{"Hello, PyObject!"};
    PyObjectLike strconcat = object_001 + " " + con_to_object_015 + '\n' + std::string(object_012) + '\n' + strconcatsv;
    std::cout << strconcat << endline;
    strconcat += "Oi";
    strconcat += strconcatsv;
    strconcat += std::string(strconcat);
    std::cout << strconcat << endline;

    std::cout << object_012 - 13333 << endline;
    std::cout << object_012 / 13333 << endline;
    std::cout << object_012 * 0 << endline;
    std::cout << int8_t(object_005) << endline;
    std::cout << int16_t(object_006) << endline;
    std::cout << int32_t(object_007) << endline;
    std::cout << int64_t(object_008) << endline;
    std::cout << uint8_t(object_009) << endline;
    std::cout << uint16_t(object_010) << endline;
    std::cout << uint32_t(object_011) << endline;
    std::cout << uint64_t(object_012) << endline;
    std::cout << std::string(object_005) << endline;
    std::cout << std::string(object_006) << endline;
    std::cout << std::string(object_007) << endline;
    std::cout << std::string(object_008) << endline;
    std::cout << std::string(object_009) << endline;
    std::cout << std::string(object_010) << endline;
    std::cout << std::string(object_011) << endline;
    std::cout << std::string(object_012) << endline;
    PyObjectLike numberstring{"3.1321"};
    double numberconverted = numberstring;
    std::cout << numberconverted << endline;
    PyObjectLike emptystring{""};
    std::cout << (bool)emptystring << endline;
    PyObjectLike notemptystring{"xxx"};
    std::cout << (bool)notemptystring << endline;
    std::cout << object_006;
    object_006++ ++ ++ ++ ++ ++;
    std::cout << object_006;
    PyObjectLike object_006b{++object_006};
    std::cout << object_006 << " " << object_006b << endline;
    object_006-- -- -- --;
    std::cout << object_006;
    PyObjectLike object_006c{--object_006};
    std::cout << object_006 << " " << object_006c << endline;

    return 0;
}
```

## Output 

```sh 
Hello, world0!
------------------------------------------------------------------
3.14
------------------------------------------------------------------
1
------------------------------------------------------------------
5
------------------------------------------------------------------
65
------------------------------------------------------------------
400
------------------------------------------------------------------
-33333
------------------------------------------------------------------
43325434453
------------------------------------------------------------------
255
------------------------------------------------------------------
65535
------------------------------------------------------------------
4294967295
------------------------------------------------------------------
18446744073709551615
------------------------------------------------------------------
Hello, world1!
------------------------------------------------------------------
Hello, world2!
------------------------------------------------------------------
Hello, world3!
------------------------------------------------------------------
{1 : 5, -33333 : 43325434453, 65 : 400, 255 : 65535, 4294967295 : 18446744073709551615, Hello, world0! : 3.14, Hello, world1! : Hello, world2!, Hello, world3! : 3.14}
------------------------------------------------------------------
{1 : 5, -33333 : 43325434453, 65 : 400, 255 : 65535, 4294967295 : 18446744073709551615, Hello, world0! : 3.14, Hello, world1! : Hello, world2!, Hello, world3! : 3.14}
------------------------------------------------------------------
{1, -33333, 5, 65, 400, 43325434453, 255, 65535, 4294967295, 18446744073709551615, 3.14, Hello, world0!, Hello, world1!, Hello, world2!, Hello, world3!}
------------------------------------------------------------------
{3.14, 400, Hello, world0!, 65, 1, 5, Hello, world1!, -33333, 43325434453, 255, 65535, 4294967295, 18446744073709551615, Hello, world2!, Hello, world3!}
------------------------------------------------------------------
[Hello, world0!, 3.14, 1, 5, 65, 400, -33333, 43325434453, 255, 65535, 4294967295, 18446744073709551615, Hello, world1!, Hello, world2!, Hello, world3!]
------------------------------------------------------------------
[Hello, world0!, 3.14, 1, 5, 65, 400, -33333, 43325434453, 255, 65535, 4294967295, 18446744073709551615, Hello, world1!, Hello, world2!, Hello, world3!]
------------------------------------------------------------------
[Hello, world0!, 3.14, 1, 5, 65]
------------------------------------------------------------------
[Hello, world0!, 3.14, 1, 5, 65]
------------------------------------------------------------------
Hello, world0! Hello, world3!
18446744073709551615
Hello, PyObject!
------------------------------------------------------------------
Hello, world0! Hello, world3!
18446744073709551615
Hello, PyObject!OiHello, PyObject!Hello, world0! Hello, world3!
18446744073709551615
Hello, PyObject!OiHello, PyObject!
------------------------------------------------------------------
-13334
------------------------------------------------------------------
0
------------------------------------------------------------------
0
------------------------------------------------------------------
A
------------------------------------------------------------------
400
------------------------------------------------------------------
-33333
------------------------------------------------------------------
43325434453
------------------------------------------------------------------
 
------------------------------------------------------------------
65535
------------------------------------------------------------------
4294967295
------------------------------------------------------------------
18446744073709551615
------------------------------------------------------------------
65
------------------------------------------------------------------
400
------------------------------------------------------------------
-33333
------------------------------------------------------------------
43325434453
------------------------------------------------------------------
255
------------------------------------------------------------------
65535
------------------------------------------------------------------
4294967295
------------------------------------------------------------------
18446744073709551615
------------------------------------------------------------------
3.1321
------------------------------------------------------------------
0
------------------------------------------------------------------
1
------------------------------------------------------------------
400401401 402
------------------------------------------------------------------
400400 399
------------------------------------------------------------------
```