

#include "libft.h"
// copy n bytes from src to dest with potentially overlapping memory

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*tmp_src;
	unsigned char	*tmp_dest;
	size_t	i;

	i = 0;
	if (src == NULL || dest == NULL)
		return (NULL);
	
	tmp_dest = (unsigned char *) dest;
	tmp_src = (const unsigned char *) src;
	if (tmp_dest > tmp_src)
	{
		while (n--)
			tmp_dest[n] = tmp_src[n];
	}
	else
	{
		while (i < n)
		{
			tmp_dest[i] = tmp_src[i];
			i++;
		}
	}
	return (dest);
}

// #include <stdio.h>
// #include <string.h>
// #include "libft.h"

// void print_result(const char *test_name, const char *expected, const char *result) {
//     if (strcmp(expected, result) == 0) {
//         printf("%s: PASS\n", test_name);
//     } else {
//         printf("%s: FAIL\n", test_name);
//         printf("Expected: %s\n", expected);
//         printf("Got: %s\n", result);
//     }
// }

// int main() {
//     char src1[] = "Hello, World!";
//     char src2[] = "Overlap Test";
//     char overlap_src[] = "Overlap Test";
//     char dest[50];
//     char overlap_dest[] = "Overlap Test";

//     // Test 1: Non-overlapping memory regions
//     ft_memmove(dest, src1, strlen(src1) + 1);
// 	memmove(dest, src1, strlen(src1) + 1);
//     print_result("Test 1 Yours", "Hello, World!", dest);
//     // Test 1: Non-overlapping memory regions
// 	memmove(dest, src1, strlen(src1) + 1);
//     print_result("Test 1 Devls", "Hello, World!", dest);

//     // Test 2: Overlapping memory regions (src before dest)
//     ft_memmove(overlap_dest + 3, overlap_src, 7);
//     print_result("Test 2 Yours", "Overlap Test", overlap_dest);
//     // Test 2: Overlapping memory regions (src before dest)
//     memmove(overlap_dest + 3, overlap_src, 7);
//     print_result("Test 2 Devls", "Overlap Test", overlap_dest);

//     // Test 3: Overlapping memory regions (dest before src)
//     ft_memmove(overlap_dest, overlap_src + 3, 7);
//     print_result("Test 3 Yours", "Overlap Test", overlap_dest);
//     // Test 3: Overlapping memory regions (dest before src)
//     memmove(overlap_dest, overlap_src + 3, 7);
//     print_result("Test 3 Devls", "Overlap Test", overlap_dest);

//     // Test 4: NULL pointers NOTE memmove() does not account for these
//     if (ft_memmove(NULL, NULL, 5) == NULL) {
//         printf("Test 4 Yours: PASS\n");
//     } else {
//         printf("Test 4 Yours: FAIL\n");
//     }
//     return 0;
// }