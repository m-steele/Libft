#include "libft.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

// To compile use: gcc -o my_test test_main.c libft.a

// This is a separate function used for testing ft_memmove
void print_result(const char *test_name, const char *expected, const char *result)
{
    if (strcmp(expected, result) == 0)
	{
        printf("%s: PASS\n\n", test_name);
    } 
	else
	{
        printf("%s: FAIL\n", test_name);
        printf("Expected: %s\n", expected);
        printf("Got: %s\n\n", result);
    }
}

int main(void)
{
	char str = '1';
	printf("\033[1;31mft_isalnum()\033[0m\n");
	printf("Your func: %d\n", ft_isalnum(str));
	printf("Devl func: %d\n\n", isalnum(str));

	printf("\033[1;31mft_isalpha()\033[0m\n");
	printf("Your func: %d\n", ft_isalpha(str));
	printf("Devl func: %d\n\n", isalpha(str));

	printf("\033[1;31mft_isascii()\033[0m\n");
	printf("Your func: %d\n", ft_isascii(str));
	printf("Devl func: %d\n\n", isascii(str));

	printf("\033[1;31mft_isdigit()\033[0m\n");
	printf("Your func: %d\n", ft_isdigit(str));
	printf("Devl func: %d\n\n", isdigit(str));

	printf("\033[1;31mft_isprint()\033[0m\n");
	printf("Your func: %d\n", ft_isprint(str));
	printf("Devl func: %d\n\n", isprint(str));

	printf("\033[1;31mft_memset()\033[0m\n");
	char h[] ="Hello!";
	printf("Orig string: %s\n", h);
	ft_memset(h, 'j', 1);
	printf("Your mod: %s\n", h);
	memset(h, 'j', 1);
	printf("Devl mod: %s\n\n", h);

// These are the tests for ft_memmove()
	printf("\033[1;31mft_memmove()\033[0m\n");
    char src1[] = "Hello, World!";
    // char src2[] = "Overlap Test";
    char overlap_src[] = "Overlap Test";
    char dst[50];
    char overlap_dest[] = "Overlap Test";

    // Test 1: Non-overlapping memory regions
    ft_memmove(dst, src1, strlen(src1) + 1);
    print_result("Test 1 Yours", "Hello, World!", dst);
    // Test 1: Non-overlapping memory regions
	memmove(dst, src1, strlen(src1) + 1);
    print_result("Test 1 Devls", "Hello, World!", dst);

    // Test 2: Overlapping memory regions (src before dest)
    ft_memmove(overlap_dest + 3, overlap_src, 7);
    print_result("Test 2 Yours", "Overlap Test", overlap_dest);
    // Test 2: Overlapping memory regions (src before dest)
    memmove(overlap_dest + 3, overlap_src, 7);
    print_result("Test 2 Devls", "Overlap Test", overlap_dest);

    // Test 3: Overlapping memory regions (dest before src)
    ft_memmove(overlap_dest, overlap_src + 3, 7);
    print_result("Test 3 Yours", "Overlap Test", overlap_dest);
    // Test 3: Overlapping memory regions (dest before src)
    memmove(overlap_dest, overlap_src + 3, 7);
    print_result("Test 3 Devls", "Overlap Test", overlap_dest);

    // Test 4: NULL pointers NOTE memmove() does not account for these
    if (ft_memmove(NULL, NULL, 5) == NULL) {
        printf("Test 4 Yours: PASS\n\n");
    } else {
        printf("Test 4 Yours: FAIL\n\n");
    }

// To test ft_strlcpy()
    printf("\033[1;31mft_strlcpy()\033[0m\n");
    char dest[20]; // Destination buffer
    size_t ret;    // To store yoru return value
    // Test 1: Normal case, source fits in destination
    ret = ft_strlcpy(dest, "Hello", sizeof(dest));
    printf("\033[1;36mTest 1: Normal copy\033[0m\n");
    printf("Source: \"Hello\"\n");
    printf("Destination: \"%s\"\n", dest);
    printf("Returned Length: %zu\n\n", ret);

    // Test 2: Source longer than destination, should truncate
    ret = ft_strlcpy(dest, "This is a long string", 10);
    printf("\033[1;36mTest 2: Truncate the string\033[0m\n");
    printf("Source: \"This is a long string\"\n");
    printf("Destination: \"%s\"\n", dest);
    printf("Returned Length: %zu\n\n", ret);

    // Test 3: Empty source string
    ret = ft_strlcpy(dest, "", sizeof(dest));
    printf("\033[1;36mTest 3: Empty source string\033[0m\n");
    printf("Source: \"\"\n");
    printf("Destination: \"%s\"\n", dest);
    printf("Returned Length: %zu\n\n", ret);

    // Test 4: Destination size is zero
    ret = ft_strlcpy(dest, "Hello", 0);
    printf("\033[1;36mTest 4: Destination size is zero\033[0m\n");
    printf("Source: \"Hello\"\n");
    printf("Destination: \"%s\"\n", dest);
    printf("Returned Length: %zu\n\n", ret);

	char text [] = "A";
    // Test 5: Source string of length 1
    ret = ft_strlcpy(dest, text, sizeof(dest));
    printf("\033[1;36mTest 5: Single character source\033[0m\n");
    printf("Source You: \"A\"\n");
    printf("Destination: \"%s\"\n", dest);
    printf("Returned Length: %zu\n\n", ret);

	printf("\033[1;31mft_toupper()\033[0m\n");
	int upper = 'A';
	int lower = 'a';
	printf("Your upper: %d\n", ft_toupper(upper));
	printf("Your lower: %d\n", ft_toupper(lower));
	printf("Their upper: %d\n", toupper(upper));
	printf("Their lower: %d\n\n", toupper(lower));

	printf("\033[1;31mft_tolower()\033[0m\n");
	printf("Your upper: %d\n", ft_tolower(upper));
	printf("Your lower: %d\n", ft_tolower(lower));
	printf("Their upper: %d\n", tolower(upper));
	printf("Their lower: %d\n\n", tolower(lower));

	printf("\033[1;31mft_strchr()\033[0m\n");
	const char string[] = "abcdefgabcdefgabcdefg";
	printf("Your 'a': %s\n", ft_strchr(string, 'a'));
	printf("Devl 'a': %s\n", strchr(string, 'a'));
	printf("Your 'g': %s\n", ft_strchr(string, 103));
	printf("Devl 'g': %s\n", strchr(string, 103));
	printf("Your 'null term': %s\n", ft_strchr(string, 0));
	printf("Devl 'null term': %s\n\n", strchr(string, 0));

	printf("\033[1;31mft_strrchr()\033[0m\n");
	printf("Your 'a': %s\n", ft_strrchr(string, 'a'));
	printf("Devl 'a': %s\n", strrchr(string, 'a'));
	printf("Your 'g': %s\n", ft_strrchr(string, 103));
	printf("Devl 'g': %s\n", strrchr(string, 103));
	printf("Your 'null term': %s\n", ft_strrchr(string, 0));
	printf("Devl 'null term': %s\n\n", strrchr(string, 0));

	printf("\033[1;31mft_strncmp()\033[0m\n");
	const char string2[] ="abcdefgabcdefgabcdefg";
	printf("Your Equal: %d\n", ft_strncmp(string, string2, 21));
	printf("Devl Equal: %d\n", strncmp(string, string2, 21));
	const char str3[] ="abcdef";
	printf("Your S1 > S2: %d\n", ft_strncmp(string, str3, 17));
	printf("Devl S1 > S2: %d\n", strncmp(string, str3, 17));
	printf("Your S1 < S2: %d\n", ft_strncmp(str3, string, 7));
	printf("Devl S1 < S2: %d\n\n", strncmp(str3, string, 7));

	printf("\033[1;31mft_memchr()\033[0m\n");
	printf("Your 'a': %p\n", ft_memchr(string, 'a', 3));
	printf("Devl 'a': %p\n", memchr(string, 'a', 3));
	printf("Your 'g': %p\n", ft_memchr(string, 103, 3));
	printf("Devl 'g': %p\n", memchr(string, 103, 3));
	printf("Your 'null term': %p\n", ft_memchr(string, 0, 20));
	printf("Devl 'null term': %p\n\n", memchr(string, 0, 20));

	printf("\033[1;31mft_memcmp()\033[0m\n");
	char str1[] ="Jsem prese";
	char str2[] ="Jsou presake";
	printf("\033[1;36mString 1:\033[0m Jsem prese\n");
	printf("\033[1;36mString 2:\033[0m Jsou presa\n\n");
	printf("\033[1;36mYour Dif:\033[0m %d\n", ft_memcmp(str1, str2, 12));
	printf("\033[1;36mDelv Dif:\033[0m %d\n\n", ft_memcmp(str1, str2, 12));
	printf("\033[1;36mYour same:\033[0m %d\n", ft_memcmp(str1, str2, 2));
	printf("\033[1;36mDelv same:\033[0m %d\n\n", ft_memcmp(str1, str2, 2));

/*NEED TO COMPLETE STRNSTR*/


	printf("\033[1;31mft_atio()\033[0m\n");
	char asciistr[] = "    -153sdfhs";
	printf("Your return: %d\n", ft_atoi(asciistr));
	printf("Devl return: %d\n", atoi(asciistr));
    return (0);
}