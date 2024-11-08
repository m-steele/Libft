#include "libft.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <fcntl.h>
#include <bsd/string.h>

// To compile use: 	gcc test_main.c libft.a -lbsd
// NOTE: -lbsd must be used to run strlcat

// This function is used to test ft_strmapi()
static char to_uppercase(unsigned int i, char c)
	{
		(void)i;
		if (c >= 'a' && c <= 'z')
			return (c - 32);
		return (c);
	}
// This function is used to test  ft_striteri()
void to_ptuppercase(unsigned int i, char *c)
	{
		(void)i;
		if (*c >= 'a' && *c <= 'z')
			*c = *c - 32;
	}
void	add_index_to_char(unsigned int i, char *c)
{
	*c += i;
}

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

// This is supposed to be the developers function which I cannot run from WSL
char *d_strnstr(const char *s, const char *find, size_t slen)
{
	char c, sc;
	size_t len;

	if ((c = *find++) != '\0') {
		len = strlen(find);
		do {
			do {
				if (slen-- < 1 || (sc = *s++) == '\0')
					return (NULL);
			} while (sc != c);
			if (len > slen)
				return (NULL);
		} while (strncmp(s, find, len) != 0);
		s--;
	}
	return ((char *)s);
}

// Supposed to be developers function strlcat()
size_t d_strlcat(char *dst, const char *src, size_t siz)
{
        char *d = dst;
        const char *s = src;
        size_t n = siz;
        size_t dlen;
        /* Find the end of dst and adjust bytes left but don't go past end */
        while (n-- != 0 && *d != '\0')
                d++;
        dlen = d - dst;
        n = siz - dlen;
        if (n == 0)
                return(dlen + strlen(s));
        while (*s != '\0') {
                if (n != 1) {
                        *d++ = *s;
                        n--;
                }
                s++;
        }
        *d = '\0';

        return(dlen + (s - src));        /* count does not include NUL */
}
// needed to include this function to free memory from ft_split()
static char	**aryfree(char **ptr, int i)
{
	while (i > 0)
	{
		i--;
		free(ptr[i]);
	}
	free(ptr);
	return(0);
}

int main(void)
{
	char str = '9';
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
	printf("Delv upper: %d\n", toupper(upper));
	printf("Delv lower: %d\n\n", toupper(lower));

	printf("\033[1;31mft_tolower()\033[0m\n");
	printf("Your upper: %d\n", ft_tolower(upper));
	printf("Your lower: %d\n", ft_tolower(lower));
	printf("Delv upper: %d\n", tolower(upper));
	printf("Delv lower: %d\n\n", tolower(lower));

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

// Takes min of dst || size; return that val plus source
// The string appended will depend on the size. It should
// append source to wherever size stops, but somehow diff
// lengths of source may occur ???
	printf("\033[1;31mft_strlcat()\033[0m\n");
	char dst_string[11] = "Ty jsi -->"; /*11*/
	const char *src_string = "velkeho prese"; /*13*/
	printf("Destination: %s\n", dst_string);
	printf("Source: %s\n", src_string);
	size_t size = 9;
	size_t ref = ft_strlcat(dst_string, src_string, size);
	printf("Your Append: %s\n", dst_string);
	printf("Your length: %zu\n\n", ref);
	// strcpy(dst_string, "Ty jsi -->");
	size_t nref = d_strlcat(dst_string, src_string, size);
	printf("Adap Append: %s\n", dst_string);
	printf("Adap length: %zu\n\n", nref);
	// strcpy(dst_string, "Ty jsi -->");
	size_t dref = strlcat(dst_string, src_string, size);
	printf("Devl Append: %s\n", dst_string);
	printf("Devl length: %zu\n\n", dref);

	printf("\033[1;31mft_strnchr()\033[0m\n");
	const char big[] = "lorem ipsum dolor sit amet";
	const char little[] = "ipsum";
	const char nothing[] = "";
	printf("Big: %s\nlittle: %s\n\n", big, little);
	printf("Your 5: %s\n", ft_strnstr(big, little, 5));
	printf("Devl 5: %s\n\n", d_strnstr(big, little, 5));
	printf("Your 30: %s\n", ft_strnstr(big, little, 30));
	printf("Devl 30: %s\n\n", d_strnstr(big, little, 30));
	printf("Your 'null term': %s\n", ft_strnstr(big, nothing, 5));
	printf("Devl 'null term': %s\n\n", d_strnstr(big, nothing, 5));
    char *result = ft_strnstr(big, little, 5);
    if (result)
        printf("Found: %s\n", result);
    else
        printf("Not Found\n");


	printf("\033[1;31mft_atio()\033[0m\n");
	char asciistr[] = "    9153sdfhs";
	printf("Your return: %d\n", ft_atoi(asciistr));
	printf("Devl return: %d\n\n", atoi(asciistr));
 
	printf("\033[1;31mft_calloc()\033[0m\n");
    size_t nmemb = 999; /*use negative to break*/
    size_t sz = sizeof(int); /*sizeof(int)*/
    int *arr;
	int *ar;
    // Use ft_calloc to allocate memory for an array of 10 integers
    arr = (int *)ft_calloc(nmemb, sz);
    // Check if memory allocation failed
    if (!arr)
    {
        printf("Your memory allocation failed!\n");
	}	
	ar = (int *)calloc(nmemb, sz);
	if (!ar)
	{
		printf("Delv memory allocation failed!\n\n");
	}
    // Check if the allocated memory is properly zeroed
    int all_zero = 1;
	int all_zero_s = all_zero;
	size_t i = 0;
	while  (i < nmemb)
    {
        if (arr[i] != 0)
        {
            all_zero = 0;
            break;
        }
		i++;
    }
	if (all_zero)
        printf("Yours passed: memory is properly zeroed.\n");
    else
        printf("Your test is'a no good!\n");
	free(arr);
    // Free the allocated memory
	size_t	ii = 0;
	while (ii < nmemb)
	{
		if (ar[ii] !=0)
		{
			all_zero_s = 0;
			break;
		}
		ii++;
	}
	if (all_zero_s)
		printf("Devls passed: memory is properly zeroed.\n\n");
	else 
		printf("Devl test is'a no good!\n\n");
	free(ar);

	printf("\033[1;31mft_memcpy()\033[0m\n");
	char dst2[50];
	ft_memcpy(dst2, str1, ft_strlen(str1) + 1);
	printf("Source: %s\n", str1);
	printf("Destin: %s\n", dst2);
	if (strcmp(str1, dst2) == 0)
		printf("Destin matches Source\n");
	else
		printf("Destin DOES NOT match Source\n\n");

	printf("\033[1;31mft_strdup()\033[0m\n");
	char s[] = "-Hello -World!";
	printf("Your copy: %s\n", ft_strdup(s));
	printf("Devl copy: %s\n\n", strdup(s));

	printf("\033[1;33mPART TWO of LIBFT - functions to end all functions\033[0m\n\n");

	printf("\033[1;31mft_substr()\033[0m\n");
	char str_sub1[]="This is your sorcestring"; /*25 characters*/
	printf("This is your sorcestring\n\n");
	printf("Should return 'string',\nYours: %s\n\n", ft_substr(str_sub1, 18, 6));
	printf("Should return NULL,\nYours: %s\n\n", ft_substr(str_sub1, 4, 0));
	printf("Should return 'This is you',\nYours: %s\n\n", ft_substr(str_sub1, 0, 11));

	printf("\033[1;31mft_strjoin()\033[0m\n");
	char s_j1[]="You do you... ";
	char s_j2[]="I do me (:p)";
	printf("String 1: %s\nString 2: %s\n", s_j1, s_j2);
	printf("Your Join Result: %s\n\n", ft_strjoin(s_j1, s_j2));

	printf("\033[1;31mft_strtrim()\033[0m\n");
	char strtotrim[] = "i am a fat pigi a m a"; /*15 chars*/
	char ctoset[] = "i am ";	 /*4 chars*/
	printf("Original: %s\nYours is: %s\n\n", strtotrim, ft_strtrim(strtotrim, ctoset));


	printf("\033[1;31mft_split()\033[0m\n");
	char splitter[]="___how_many_____words_in_this_string?__five_or_six?___";
	char delimiter[]="";
 	char **words;
    int spliti;
    words = ft_split(splitter, *delimiter);
	printf("String: %s, Delimiter: %c\n", splitter, *delimiter);
    for (spliti = 0; words[spliti] != NULL; spliti++)
    	printf("%s\n", words[spliti]);
    aryfree(words, spliti);

	printf("\033[1;31mft_itoa()\033[0m\n");
	int itoa_n1 = 757689;
	printf("Number 757689 is: %s\n\n", ft_itoa(itoa_n1));
	int itoa_n3 = 0;
	printf("Number 0 is: %s\n\n", ft_itoa(itoa_n3));
	int itoa_n = -2147483648;
	printf("Number -2147483648 is: %s\n\n", ft_itoa(itoa_n));
	int itoa_n2 = -1483648;
	printf("Number -1483648 is: %s\n\n", ft_itoa(itoa_n2));
	int itoa_n4 = 1483648;
	printf("Number 1483648 is: %s\n\n", ft_itoa(itoa_n4));
	int itoa_n5 = -1;
	printf("Number -1 is: %s\n\n", ft_itoa(itoa_n5));

	printf("\033[1;31mft_strmapi()\033[0m\n");
	printf("Original: %s\n", splitter);
	printf("Modified: %s\n\n", ft_strmapi(splitter, to_uppercase));

	printf("\033[1;31mft_striteri()\033[0m\n");
	printf("Original 1: %s\n", splitter);
	ft_striteri(splitter, to_ptuppercase);
	printf("Modified 1: %s\n\n", splitter);
	printf("Original 2: %s\n", splitter);
	ft_striteri(splitter, add_index_to_char);
	printf("Modified 2: %s\n\n", splitter);

	printf("\033[1;31mft_putchar_fd()\033[0m\n");
	ft_putchar_fd('A', 1);
	write(1, "\n", 1);
	ft_putchar_fd('B', 2);
	write(2, "\n\n", 2);
	int fd_char = open("test_output1.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_char == -1)
		{
			write(2, "Failed to open file\n", 20);
			return (1);
		}
	ft_putchar_fd('C', fd_char);
	close(fd_char);
	printf("Char has been written to test_output1.txt\n\n");

	printf("\033[1;31mft_putstr_fd()\033[0m\n");
	int fd_str = open("test_output2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_str < 0)
	{
		printf("Error opening file!\n");
		return (1);
	}
	ft_putstr_fd(str1, fd_str);
	close(fd_str);
	printf("String has been written to test_output2.txt\n\n");

	printf("\033[1;31mft_putendl_fd()\033[0m\n");
	int fd_nl = open("test_output3.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_nl < 0)
	{
		printf("Error opening file!\n");
		return (1);
	}
	ft_putendl_fd(str1, fd_nl);
	close(fd_nl);
	printf("String has been written to test_output3.txt\n\n");

	
	printf("\033[1;31mft_putnbr_fd()\033[0m\n");
	int fd_nbr = open("test_output4.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_nbr < 0)
	{
		printf("Error opening file!\n");
		return (1);
	}
	ft_putnbr_fd(1583541, fd_nbr);
	close(fd_nbr);
	printf("Int has been written to test_output4.txt\n\n");
return (0);
}