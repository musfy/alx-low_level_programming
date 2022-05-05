<p>Read this page, write down and test all the examples (do not copy-paste!).</p>

<h2>Pointers</h2>

<p><img src="https://github.com/musfy/alx-low_level_programming/blob/master/digim/pointers.jpg" alt="" style="" /><br>
<br/><br />
<strong>A pointer is a variable which contains a memory address.</strong></p>

<h3>Types and memory</h3>

<p>Every time you declare a variable, the computer will reserve memory for this variable. The memory reserved will then store the value of the variable.<br>
Depending on the type of the variable, the computer will reserve more or less memory. The size of each type is generally defined in bytes (1 byte = 8 bits, each bit being 0 or 1).
The sizes of the types also depend on the computer you are using. Here are the sizes of the most common types on most 64-bit Linux machines:  </p>

<ul>
<li>char -&gt; 1 byte<br></li>
<li>int -&gt; 4 bytes<br></li>
<li>float -&gt; 4 bytes</li>
</ul>

<p>To determine the size of those types on your computer, you can use the <code>sizeof</code> operator.  </p>

<pre><code>ubuntu@ip-172-31-63-244:~/julien$ cat 0-main.c
#include &lt;stdio.h&gt;

/**
 * main - using sizeof to dynamically determine the size of types char, int and float
 *
 * Return: Always 0.
 */
int main(void)
{
   int n; 

   printf(&quot;Size of type &#39;char&#39; on my computer: %lu bytes\n&quot;, sizeof(char));
   printf(&quot;Size of type &#39;int&#39; on my computer: %lu bytes\n&quot;, sizeof(int));
   printf(&quot;Size of type &#39;float&#39; on my computer: %lu bytes\n&quot;, sizeof(float));
   printf(&quot;Size of type of my variable n on my computer: %lu bytes\n&quot;, sizeof(n));
   return (0);
}
ubuntu@ip-172-31-63-244:~/julien$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 0-main.c -o sizeof &amp;&amp; ./sizeof
Size of type &#39;char&#39; on my computer: 1 bytes
Size of type &#39;int&#39; on my computer: 4 bytes
Size of type &#39;float&#39; on my computer: 4 bytes
Size of type of my variable n on my computer: 4 bytes
</code></pre>

<p>The size of a type will determine how many different possible values a variable of this type can hold. For instance, a <code>char</code> variable could only hold 256 (2^8, 8 being the number of bits) different values: from -128 to 127. And because the size of <code>int</code> is 4 bytes, so 32 bits, an <code>int</code> variable can hold 2^32 different possible values.</p>

<p>When we declare a variable, the computer will reserve the right amount of space for the variable in the memory (depending on its type). The space reserved for the variable is its address. And when we assign a value to this variable, the computer will store this value at its address.  </p>

<pre><code>char c;  
</code></pre>

<p><img src="/https://github.com/musfy/alx-low_level_programming/blob/master/digim/char_c_declaration.png" alt="" style="" />  </p>

<p>In this example, we simply declare a variable <code>c</code> of type <code>char</code>. The address of <code>c</code> is <code>8</code>. At this stage, you have not assigned a value to your variable <code>c</code>. So you do not know its value. It depends on what this memory address was used for before. You should never assumed that it is 0.  </p>

<pre><code>char c;  

c = &#39;H&#39;;  
</code></pre>

<p>When we assign the value <code>&#39;H&#39;</code> to <code>c</code>, then <code>&#39;H&#39;</code> is stored at <code>c</code>&lsquo;s address.  </p>

<p><img src="https://github.com/musfy/alx-low_level_programming/blob/master/digim/char_c_H.png" alt="" style="" />  </p>

<p>But you know that a byte can only store numbers. So actually, the byte will not hold exactly the letter <code>&#39;H&#39;</code>, but its ascii code, which is <code>72</code> (man ascii). So it really looks like this in memory:  </p>

<p><img src="https://github.com/musfy/alx-low_level_programming/blob/master/digim/char_c_72.png" alt="" style="" />  </p>

<p>Since integers are stored within four bytes of memory, the same example with an <code>int</code> variable would look like this:  </p>

<pre><code>int n;  

n = 98;  
</code></pre>

<p><img src="https://github.com/musfy/alx-low_level_programming/blob/master/digim/int_n_98.png" alt="" style="" />  </p>

<p>In this example, the address of the variable <code>n</code> is the smallest address of its bytes, so in this example, <code>26</code>.<br>
Note that you do not control the address where the variable is stored. In order to know what is the address of a variable, you can use the &ldquo;address-of unary operator&rdquo; <code>&amp;</code>.  </p>

<pre><code>ubuntu@ip-172-31-63-244:~/julien$ cat 1-main.c
#include &lt;stdio.h&gt;

/**
 * main - addresses of variables
 *
 * Return: Always 0.
 */
int main(void)
{
   char c;
   int n;

   printf(&quot;Address of variable &#39;c&#39;: %p\n&quot;, &amp;c);
   printf(&quot;Address of variable &#39;n&#39;: %p\n&quot;, &amp;n);
   return (0);
}
ubuntu@ip-172-31-63-244:~/julien$ gcc 1-main.c -o address &amp;&amp; ./address
Address of variable &#39;c&#39;: 0x7ffc370ef13b
Address of variable &#39;n&#39;: 0x7ffc370ef13c
</code></pre>

<p>Note that:  </p>

<ul>
<li>You can use <code>%p</code> to print addresses (the values of pointers) with <code>printf</code></li>
<li>This example will not compile with our regular flags <code>-Wall -Wextra -Werror -pedantic -std=gnu89</code>. You&rsquo;ll learn why later</li>
</ul>

<h3>Storing memory addresses</h3>

<p>Now that we know how to get an address, we can store it in a&hellip; pointer! :)<br>
A pointer is simply the address of a piece of data in memory. A pointer variable is a variable that stores the address of that piece of data. Like any other variable it needs to be declared. General form is:<br>
<code>var_type *var;</code>  </p>

<ul>
<li>The <code>*</code> tells that the variable <code>var</code> is a pointer&hellip;<br></li>
<li>&hellip; that points to a var_type.</li>
<li>The value of <code>var</code> will be a memory address holding a value of type <code>var_type</code></li>
</ul>

<pre><code>int *ptr;  
</code></pre>

<p>In this example, <code>ptr</code> is the name of the variable, of type &ldquo;pointer to an integer&rdquo;. Anything that is on the left of the last <code>*</code> before the name of the variable will give you the type that the pointer points to.  </p>

<pre><code>/* ptr2 is a pointer to a char */  
char *ptr2  
</code></pre>

<p>Because a pointer is like any other variable, the computer will also reserve the right amount of memory for it to store its value. On most 64 bits machines, the size of pointers is 8 bytes.  </p>

<pre><code>ubuntu@ip-172-31-63-244:~/julien$ cat 2-main.c
#include &lt;stdio.h&gt;

/**
 * main - printing the size, in bytes, of a pointer
 *
 * Return: Always 0.
 */
int main(void)
{
   int *p;

   printf(&quot;Size of pointer: %lu\n&quot;, sizeof(p));
   return (0);
}
ubuntu@ip-172-31-63-244:~/julien$ gcc -Wall -Werror -pedantic -Wextra -std=gnu89 2-main.c -o psize &amp;&amp; ./psize
Size of pointer: 8
</code></pre>

<p><img src="https://github.com/musfy/alx-low_level_programming/blob/master/digim/p.png" alt="" style="" />  </p>

<p>To get the address where a pointer is stored, you can use the same technique as for any other variable: use the <code>&amp;</code> operator. </p>

<pre><code>ubuntu@ip-172-31-63-244:~/julien$ cat 3-main.c
#include &lt;stdio.h&gt;

/**
 * main - printing the address of a pointer
 *
 * Return: Always 0.
 */
int main(void)
{
  int *p;

  printf(&quot;Address of variable &#39;p&#39;: %p\n&quot;, &amp;p);
  return (0);
}
ubuntu@ip-172-31-63-244:~/julien$ gcc 3-main.c -o paddress &amp;&amp; ./paddress
Address of variable &#39;p&#39;: 0x7ffc9efc0de8
</code></pre>

<p>Ok, now let&rsquo;s store the address of a variable into a pointer.  </p>

<pre><code>int n;
int *p; 

n = 98;
p = &amp;n;  
</code></pre>

<p>Because <code>&amp;n</code> gives us the address of the variable <code>n</code>, the variable <code>p</code> now holds the address of the variable <code>n</code>: <code>p</code> points to <code>n</code>. If the variable <code>n</code>&rsquo;s address were 26, then the value of our pointer <code>p</code> would be 26.  </p>

<p><img src="https://github.com/musfy/alx-low_level_programming/blob/master/digim/p_n.png" alt="" style="" />  </p>

<pre><code>ubuntu@ip-172-31-63-244:~/julien$ cat 4-main.c
#include &lt;stdio.h&gt;

/**
 * main - storing the address of variable into a pointer
 *
 * Return: Always 0.
 */
int main(void)
{
  int n;
  int *p;

  n = 98;
  p = &amp;n;
  printf(&quot;Address of &#39;n&#39;: %p\n&quot;, &amp;n);
  printf(&quot;Value of &#39;p&#39;: %p\n&quot;, p);
  return (0);
}
ubuntu@ip-172-31-63-244:~/julien$ gcc 4-main.c -o pn &amp;&amp; ./pn
Address of &#39;n&#39;: 0x7ffc6f64b6d4
Value of &#39;p&#39;: 0x7ffc6f64b6d4
</code></pre>

<p>Remember that a pointer can only point to a variable of the type it is supposed to point to. The following example is incorrect:  </p>

<pre><code>char c;  
int *p;  

p = &amp;c;  
</code></pre>

<h3>Dereferencing</h3>

<p>You could argue that so far, we could have used an integer (or a <code>unsigned long int</code> that is also 8 bytes long on most 64 bits computers) to store an address, since it is a number. The real power of pointers is that they can manipulate values stored at the memory address they point to. This is called dereferencing. To do this, you can use the dereference operator <code>*</code>.  </p>

<pre><code>ubuntu@ip-172-31-63-244:~/julien$ cat 5-main.c
#include &lt;stdio.h&gt;

/**
 * main - derefencing pointers
 *
 * Return: Always 0.
 */
int main(void)
{
   int n;
   int *p;

   n = 98;
   p = &amp;n;
   printf(&quot;Value of &#39;n&#39;: %d\n&quot;, n);
   printf(&quot;Address of &#39;n&#39;: %p\n&quot;, &amp;n);
   printf(&quot;Value of &#39;p&#39;: %p\n&quot;, p);
   *p = 402;
   printf(&quot;Value of &#39;n&#39;: %d\n&quot;, n);
   return (0);
}
ubuntu@ip-172-31-63-244:~/julien$ gcc 5-main.c -o dereference &amp;&amp; ./dereference
Value of &#39;n&#39;: 98
Address of &#39;n&#39;: 0x7ffd9c1969a4
Value of &#39;p&#39;: 0x7ffd9c1969a4
Value of &#39;n&#39;: 402
</code></pre>

<p>Let&rsquo;s walk through this example:</p>

<ul>
<li><code>int *p;</code>: <code>*</code> is used in the declaration: <code>p</code> is a pointer to an integer, and so, after dereferencing, <code>*p</code> is an integer.<br></li>
<li><code>p = &amp;n;</code>: <code>&amp;</code> takes the address of <code>n</code>. So now <code>p</code> == <code>&amp;n</code>, so <code>*p == n</code><br></li>
</ul>

<p>At this point, the memory looks like this:  </p>

<p><img src="https://github.com/musfy/alx-low_level_programming/blob/master/digim/p_n.png" alt="" style="" />  </p>

<ul>
<li><code>*p = 402;</code>: equivalent to <code>n</code> = <code>402</code>, since <code>p</code> == <code>&amp;n</code>. Now <code>*p</code> == <code>402</code> so <code>n</code> == <code>402</code>. </li>
</ul>

<p>This is what it looks like after this statement in memory:  </p>

<p><img src="https://github.com/musfy/alx-low_level_programming/blob/master/digim/p_n_402.png" alt="" style="" />  </p>

<p>This works exactly the same for other types:</p>

<pre><code>ubuntu@ip-172-31-63-244:~/julien$ cat 6-main.c
#include &lt;stdio.h&gt;

/**
 * main - derefencing pointers, example with int and char types
 *
 * Return: Always 0.
 */
int main(void)
{
   int n;
   int *p;
   char c;
   char *pp;

   c = &#39;H&#39;;
   pp = &amp;c;
   n = 98;
   p = &amp;n;
   printf(&quot;Value of &#39;c&#39;: %d (&#39;%c&#39;)\n&quot;, c, c);
   printf(&quot;Address of &#39;c&#39;: %p\n&quot;, &amp;c);
   printf(&quot;Value of &#39;pp&#39;: %p\n&quot;, pp);
   printf(&quot;Value of &#39;n&#39;: %d\n&quot;, n);
   printf(&quot;Address of &#39;n&#39;: %p\n&quot;, &amp;n);
   printf(&quot;Value of &#39;p&#39;: %p\n&quot;, p);
   *p = 402;
   *pp = &#39;o&#39;;
   printf(&quot;Value of &#39;n&#39;: %d\n&quot;, n);
   printf(&quot;Value of &#39;*pp&#39;: %d\n&quot;, *pp);
   printf(&quot;Value of &#39;c&#39;: %d (&#39;%c&#39;)\n&quot;, c, c);
   printf(&quot;Value of &#39;*pp&#39;: %d (&#39;%c&#39;)\n&quot;, *pp, *pp);
   return (0);
}
ubuntu@ip-172-31-63-244:~/julien$ gcc 6-main.c -o dereference2 &amp;&amp; ./dereference2
Value of &#39;c&#39;: 72 (&#39;H&#39;)
Address of &#39;c&#39;: 0x7ffe57e9cc7b
Value of &#39;pp&#39;: 0x7ffe57e9cc7b
Value of &#39;n&#39;: 98
Address of &#39;n&#39;: 0x7ffe57e9cc7c
Value of &#39;p&#39;: 0x7ffe57e9cc7c
Value of &#39;n&#39;: 402
Value of &#39;*pp&#39;: 111
Value of &#39;c&#39;: 111 (&#39;o&#39;)
Value of &#39;*pp&#39;: 111 (&#39;o&#39;)
</code></pre>

<p>Note that <code>*</code> has a different meaning depending on the context (declaring vs dereferencing pointers).</p>

<ul>
<li>at declaration, it is used to declare a variable of type pointer to something. Example: <code>int *n;</code></li>
<li>when used inside the code it is used to dereference pointers. Example <code>*n = 98;</code></li>
</ul>

<h3>Functions parameters are passed by value</h3>

<p>When we call a function in C, parameters are copied.  </p>

<pre><code>/**
 * modif_my_param - this function does not modify n
 * @m: a useless integer
 *
 * Return: nothing.
 */
void modif_my_param(int m)
{
   m = 402;
}

/**
 * main - parameters are passed by value
 *
 * Return: Always 0.
 */
int main(void)
{
   int n;

   n = 98;
   modif_my_param(n);
   return (0);
}

</code></pre>

<p>In this example, when we call the <code>modif_my_param</code> function, the value of n (98) is copied inside a new variable m, only available in the <code>modif_my_param</code> function. Here is what it looks like in memory before the line <code>m = 402;</code> is executed:  </p>

<p><img src="https://github.com/musfy/alx-low_level_programming/blob/master/digim/n_m.png" alt="" style="" />  </p>

<p>After <code>m = 402;</code> the memory looks like this:  </p>

<p><img src="https://github.com/musfy/alx-low_level_programming/blob/master/digimnm402.png" alt="" style="" />  </p>

<p>When we leave the function <code>modif_my_param</code> the variable <code>m</code> is destroyed and does not exist anymore. Its value though, stays in memory until this space is used by the program for another variable or something else.  </p>

<p><img src="https://github.com/musfy/alx-low_level_programming/blob/master/digim/nomorem.png" alt="" style="" />  </p>

<p>This rule applies to any type of variable.
But since the values of pointers are addresses, it is possible to modify a variable from outside the function it is declared, using a pointer.  </p>

<pre><code>ubuntu@ip-172-31-63-244:~/julien$ cat 7-main.c
#include &lt;stdio.h&gt;

/**
 * modif_my_param - set the integer to 402
 * @m: a pointer the integer we want to set to 402
 *
 * Return: nothing
 */
void modif_my_param(int *m)
{
   printf(&quot;Value of &#39;m&#39;: %p\n&quot;, m);
   printf(&quot;Address of &#39;m&#39;: %p\n&quot;, &amp;m);
   *m = 402;
}

/**
 * main - how to change the value of a variable from outside the function
 * it is declared in, using a pointer.
 *
 * Return: Always 0.
 */
int main(void)
{
   int n;
   int *p;

   p = &amp;n;
   n = 98;
   printf(&quot;Value of &#39;n&#39; before the call: %d\n&quot;, n);
   printf(&quot;Address of &#39;n&#39;: %p\n&quot;, &amp;n);
   printf(&quot;Value of &#39;p&#39;: %p\n&quot;, p);
   printf(&quot;Address of &#39;p&#39;: %p\n&quot;, &amp;p);
   modif_my_param(p);
   printf(&quot;Value of &#39;n&#39; after the call: %d\n&quot;, n);
   return (0);
}
ubuntu@ip-172-31-63-244:~/julien$ gcc 7-main.c -o modify_param &amp;&amp; ./modify_param
Value of &#39;n&#39; before the call: 98
Address of &#39;n&#39;: 0x7ffd70432494
Value of &#39;p&#39;: 0x7ffd70432494
Address of &#39;p&#39;: 0x7ffd70432498
Value of &#39;m&#39;: 0x7ffd70432494
Address of &#39;m&#39;: 0x7ffd70432478
Value of &#39;n&#39; after the call: 402
</code></pre>

<p>In this example, here is what happens: Before the call to the function <code>modif_my_param</code>, the memory looks like this: </p>

<p><img src="https://github.com/musfy/alx-low_level_programming/blob/master/digim/before_call.png" alt="" style="" />  </p>

<p>When we call the function <code>modif_my_param</code>, the value of <code>p</code> is stored in a new variable called <code>m</code>:  </p>

<p><img src="https://github.com/musfy/alx-low_level_programming/blob/master/digim/call.png" alt="" style="" />  </p>

<p>Since <code>m</code> stores the same memory address, it points to the same address, and so both <code>p</code> and <code>m</code> now point to <code>n</code>. Therefore, when we execute the line <code>*m = 402;</code> we modify the value of <code>n</code> and <code>n</code> now holds <code>402</code>.  </p>

<p><img src="https://github.com/musfy/alx-low_level_programming/blob/master/digim/n402.png" alt="" style="" />  </p>

<p>When we leave the function <code>modif_my_param</code>, the variable <code>m</code> is destroyed, but <code>n</code>&rsquo;s value is still <code>402</code>:</p>

<p><img src="https://github.com/musfy/alx-low_level_programming/blob/master/digim/exitfunction.png" alt="" style="" />  </p>

<p>Using the same format, try to represent in memory what is happening at every step of the following program. When done, add some <code>printf</code>s and compile to verify your hypothesis.  </p>

<pre><code>/**
 * modif_my_char_var - Solve me
 *
 * Return: nothing.
 */
void modif_my_char_var(char *cc, char ccc)  
{
   *cc = &#39;o&#39;;
   ccc = &#39;l&#39;;
}

/**
 * main - Solve me
 *
 * Return: Always 0.
 */
int main(void)
{
   char c;
   char *p;

   p = &amp;c;
   c = &#39;H&#39;;
   modif_my_char_var(p, c);
   return (0);
}
</code></pre>

# Arrays

<p>Arrays in C are contiguous memory areas that hold a number of values of the same type. Unlike some other languages, in C, all elements of an array have the same type. To declare an array we use this syntax: <code>type var_name[number_of_elements];</code>, where <code>number_of_elements</code> is the number of elements of type <code>type</code> that we need. </p>

<pre><code>int t[5];  
</code></pre>

<p>In this example we declare an array of 5 integers. The computer will reserve a continuous space for 5 integers in memory. In memory, it would look like something like this.</p>

<p><img src="https://github.com/musfy/alx-low_level_programming/blob/master/digim/f39bb24c846b2d92767d7c46531cea7dc3fb11d2.png" alt="" style="" />  </p>

<p>We access the different elements of an array this way: <code>t[0]</code> will access the first element, <code>t[1]</code> the second element, and so on.  </p>

<pre><code>ubuntu@ip-172-31-63-244:~/julien$ cat 9-main.c
#include &lt;stdio.h&gt;

/**
 * main - Accessing the different elements of an array
 *
 * Return: Always 0.
 */
int main(void)
{
   int a[5];

   a[0] = 98;
   a[1] = 198;
   a[2] = 298;
   a[3] = 398;
   a[4] = 498;
   printf(&quot;Value of a[0]: %d\n&quot;, a[0]);
   printf(&quot;Value of a[1]: %d\n&quot;, a[1]);
   printf(&quot;Value of a[2]: %d\n&quot;, a[2]);
   printf(&quot;Value of a[3]: %d\n&quot;, a[3]);
   printf(&quot;Value of a[4]: %d\n&quot;, a[4]);
   printf(&quot;Address of &#39;a[0]&#39;: %p\n&quot;, &amp;(a[0]));
   printf(&quot;Address of &#39;a[1]&#39;: %p\n&quot;, &amp;(a[1]));
   printf(&quot;Address of &#39;a[2]&#39;: %p\n&quot;, &amp;(a[2]));
   printf(&quot;Address of &#39;a[3]&#39;: %p\n&quot;, &amp;(a[3]));
   printf(&quot;Address of &#39;a[4]&#39;: %p\n&quot;, &amp;(a[4]));
   return (0);
}
ubuntu@ip-172-31-63-244:~/julien$ gcc 9-main.c -o array &amp;&amp; ./array
Value of a[0]: 98
Value of a[1]: 198
Value of a[2]: 298
Value of a[3]: 398
Value of a[4]: 498
Address of &#39;a[0]&#39;: 0x7ffcbca77dd0
Address of &#39;a[1]&#39;: 0x7ffcbca77dd4
Address of &#39;a[2]&#39;: 0x7ffcbca77dd8
Address of &#39;a[3]&#39;: 0x7ffcbca77ddc
Address of &#39;a[4]&#39;: 0x7ffcbca77de0
</code></pre>

<p>Memory would look like this before exiting the <code>main</code> function:  </p>

<p><img src="https://github.com/musfy/alx-low_level_programming/blob/master/digim/endmain.png" alt="" style="" />  </p>

# Pointers vs Arrays

<p>In C, <strong>an array is NOT a pointer</strong>, the variables we declare as arrays do not hold a memory address.</p>

<p>When we declare an array, we use a name to refer to it, but it is only a name. Array names are identifiers that identify the entire array object. They are not pointers to anything. That is why we can not change the value of a &#39;variable&rsquo; which is an array.</p>

<pre><code>julien@ubuntu:~/c/$ cat 10-main.c
/**
 * main - You can not modify a 
 *
 * Return: Always 0.
 */
int main(void)
{
    int a[5];
    int b;
    int c[5];

    a = 0; /* nop */
    a = &amp;b; /* nop */
    a = c; /* nop */
    return (0);
}
julien@ubuntu:~/c/ideas_tests$ gcc 10-main.c
10-main.c: In function ‘main’:
10-main.c:12:4: error: assignment to expression with array type
  a = 0; /* nop */
    ^
10-main.c:13:4: error: assignment to expression with array type
  a = &amp;b; /* nop */
    ^
10-main.c:14:4: error: assignment to expression with array type
  a = c; /* nop */
    ^
julien@ubuntu:~/c$ 
</code></pre>

<p>But, you can still use the name of the array in your code, and its value will be&hellip; the address of the first element of the array. Wait&hellip; WAT?</p>

<p><img src="https://github.com/musfy/alx-low_level_programming/blob/master/digim/wat.gif" alt="" style="" />  </p>

<pre><code>ubuntu@ip-172-31-63-244:~/julien$ cat 16-main.c
#include &lt;stdio.h&gt;

/**
 * main - An array is not a pointer, but...
 *
 * Return: Always 0.
 */
int main(void)
{
   int a[98]; /* array */

   printf(&quot;a: %p\n&quot;, a);
   printf(&quot;&amp;a[0]: %p\n&quot;, &amp;a[0]);
   return (0);
}
ubuntu@ip-172-31-63-244:~/julien$ gcc 16-main.c -o avsp &amp;&amp; ./avsp
a: 0x7fffc211caa0
&amp;a[0]: 0x7fffc211caa0
</code></pre>

<p>So what is happening here? If arrays are not pointers, why is it that the value of an array is the address of the first element of the same array. Isn&rsquo;t this the definition of a pointer: &ldquo;a variable which contains the address&rdquo;? Well&hellip; YES, this is a pointer, but the variable <code>a</code> (the array) is NOT. This is why:</p>

<p>When the name of an array is used in an expression, the array type gets automatically implicitly converted to pointer-to-element type in almost all contexts (this is often referred to as &ldquo;array type decay&rdquo;). The resultant pointer is a completely independent temporary value, that is the address of the first element of the array.  </p>

<pre><code>ubuntu@ip-172-31-63-244:~/julien$ cat 17-main.c
#include &lt;stdio.h&gt;
void f(int *a);

/**
 * main - Illustrating the array type decay
 *
 * Return: Always 0.
 */
int main(void)
{
   int *p;
   int t[10];

   p = t; /* This works because of the auto implicit conversion to (int *) */
   printf(&quot;t: %p\n&quot;, t);
   printf(&quot;&amp;t[0]: %p\n&quot;, &amp;t[0]);
   printf(&quot;p: %p\n&quot;, p);
   f(t);
   return (0);
}

/**
 * f - prints the value of a pointer of type int
 * @a: address of an integer we need to print
 *
 * Return: Nothing.
 */
void f(int *a)
{
   printf(&quot;a: %p\n&quot;, a);
   return;
}
ubuntu@ip-172-31-63-244:~/julien$ gcc 17-main.c &amp;&amp; ./a.out
t: 0x7ffd553e7380
&amp;t[0]: 0x7ffd553e7380
p: 0x7ffd553e7380
a: 0x7ffd553e7380
</code></pre>

<p>There are two exceptions to this: when the array name is an operand of <code>sizeof</code> or unary <code>&amp;</code> (address-of), the name of the array then refers to the array object itself.  </p>

<p><strong>sizeof</strong></p>

<p>In the context of <code>sizeof</code>, the name of the array refers to the array object itself (composed of all its elements). Thus, <code>sizeof</code> an array will give you the amount of memory space used by all its elements.  </p>

<pre><code>ubuntu@ip-172-31-63-244:~/julien$ cat 14-main.c
#include &lt;stdio.h&gt;

/**
 * main - printing the sizeof an array 
 *
 * Return: Always 0.
 */
int main(void)
{
   int array[10];

   printf(&quot;sizeof array: %lu\n&quot;, sizeof(array));
   return (0);  
}
ubuntu@ip-172-31-63-244:~/julien$ gcc -Wall -Werror -Wextra -pedantic -o sizeofarray 14-main.c &amp;&amp; ./sizeofarray
sizeof array: 40  
</code></pre>

<p><strong>&amp;</strong> </p>

<p>In the context of <code>&amp;</code>, the name of the array refers to the array object itself (composed of all its elements). So the <code>address-of</code> the array name will give you the address of the whole array, which is the same as the address of its first element.  </p>

<pre><code>ubuntu@ip-172-31-63-244:~/julien/curriculum_by_julien/low_level_programming/pointers$ cat 18-main.c
#include &lt;stdio.h&gt;

/**
 * main - prints the address of an array
 *
 * Return: Always 0.
 */
int main(void)
{
   char b[98];

   printf(&quot;b: %p\n&quot;, b);
   printf(&quot;&amp;b: %p\n&quot;, &amp;b);
   return (0);
}
ubuntu@ip-172-31-63-244:~/julien/curriculum_by_julien/low_level_programming/pointers$ gcc 18-main.c &amp;&amp; ./a.out
b: 0x7fff6130ef60
&amp;b: 0x7fff6130ef60
</code></pre>

<p>As a consequence, the value of <code>b</code> is the same as the value of <code>&amp;b</code>. But they do not have the same type:  </p>

<ul>
<li><code>b</code>: in this context, general rule applies, so using <code>b</code> will be evaluated as the address of the first element of the array. Thus, <code>b</code> is of type <code>char *</code><br></li>
<li><code>&amp;b</code>: in this context (one of the two exceptions to the general rule), <code>b</code> will be evaluated as the array object itself. so <code>b</code> is of type <code>char[98]</code> - an array of 98 characters - and then <code>&amp;b</code> is of type <code>char (*)[98]</code>, a pointer to an array of 98 characters.<br></li>
</ul>

<p>This is important because when we will manipulate those two pointers, they will behave differently, since the size of their type is different:  </p>

<ul>
<li><code>sizeof</code> <code>b</code> is <code>98</code> (see above)<br></li>
<li><code>sizeof</code> <code>&amp;b</code> is 8, (if you are using a regular 64 bits machine)   (see below)<br></li>
</ul>

<pre><code>ubuntu@ip-172-31-63-244:~/julien/curriculum_by_julien/low_level_programming/pointers$ cat 19-main.c
#include &lt;stdio.h&gt;

/**
 * main - prints the size of an array and the address of an array
 *
 * Return: Always 0.
 */
int main(void)
{
   char b[98];

   printf(&quot;b: %p\n&quot;, b);
   printf(&quot;&amp;b: %p\n&quot;, &amp;b);
   printf(&quot;sizeof(b): %lu\n&quot;, sizeof(b));
   printf(&quot;sizeof(&amp;b): %lu\n&quot;, sizeof(&amp;b));
   return (0);
}
ubuntu@ip-172-31-63-244:~/julien/curriculum_by_julien/low_level_programming/pointers$ gcc 19-main.c &amp;&amp; ./a.out
b: 0x7ffe0b9c62f0
&amp;b: 0x7ffe0b9c62f0
sizeof(b): 98
sizeof(&amp;b): 8
</code></pre>

#












Pointers Arithmetic

<p>Another way to access different elements of an array, is to use this other notation: <code>*(var + x)</code>, where <code>var</code> is the name of an array, and <code>x</code> is the (x+1)th element (starting counting elements at 0 of course) of this array. For instance if we declare:  </p>

<pre><code>int i[10];  
</code></pre>

<p>then, when we will use <code>i</code> in the code, <code>i[5]</code> will be the same as <code>*(i + 5)</code>. We already knew that <code>i</code> is evaluated as a pointer to the first element of the array, since <code>i</code> is an array. But now, we also know that <code>i + 5</code> will be evaluated as a pointer to the 6th element of the array <code>i</code>.  </p>

<pre><code>ubuntu@ip-172-31-63-244:~/julien/curriculum_by_julien/low_level_programming/pointers$ cat 10-main.c
#include &lt;stdio.h&gt;

/**
 * main - illustrates pointers arithmetic
 *
 * Return: Always 0.
 */
int main(void)
{
   int a[5];

   *a = 98; /* same as *(a + 0) */
   *(a + 1) = 198;
   *(a + 2) = 298;
   *(a + 3) = 398;
   *(a + 4) = 498;
   printf(&quot;Value of a[0]: %d\n&quot;, *a);
   printf(&quot;Value of a[1]: %d\n&quot;, *(a + 1));
   printf(&quot;Value of a[2]: %d\n&quot;, *(a + 2));
   printf(&quot;Value of a[3]: %d\n&quot;, *(a + 3));
   printf(&quot;Value of a[4]: %d\n&quot;, *(a + 4));
   printf(&quot;----------------\n&quot;);
   printf(&quot;Value of &#39;a&#39; (also address of a[0]): %p\n&quot;, a);
   printf(&quot;Address of &#39;a[1]&#39;: %p\n&quot;, (a + 1));
   printf(&quot;Address of &#39;a[1]&#39;: %p\n&quot;, &amp;(*(a + 1)));
   return (0);
}
ubuntu@ip-172-31-63-244:~/julien/curriculum_by_julien/low_level_programming/pointers$ gcc 10-main.c -o array &amp;&amp; ./array
Value of a[0]: 98
Value of a[1]: 198
Value of a[2]: 298
Value of a[3]: 398
Value of a[4]: 498
----------------
Value of &#39;a&#39; (also address of a[0]): 0x7ffff8f19240
Address of &#39;a[1]&#39;: 0x7ffff8f19244
Address of &#39;a[1]&#39;: 0x7ffff8f19244
</code></pre>

<p>But wait a second, if the value of <code>a</code> is <code>0x7ffff8f19240</code>, how come <code>a + 1</code> == <code>0x7ffff8f19244</code> and not <code>0x7ffff8f19241</code>?<br>
This is the pointers arithmetic. The computer knows   that <code>a</code> points to an integer. The computer also knows that the size of an integer in memory is <code>sizeof(int)</code> bytes - in this case 4 bytes - and concludes that the next element of this type will be stored 4 bytes later in memory.  </p>

<p><img src="https://github.com/musfy/alx-low_level_programming/blob/master/digim/arithm.png" alt="" style="" />  </p>

<p>If this works for arrays, which are evaluated as pointers in this context, this means that this arithmetic also works for &ldquo;regular&rdquo; pointers.</p>

<pre><code>ubuntu@ip-172-31-63-244:~/julien$ cat 20-main.c
#include &lt;stdio.h&gt;

/**
 * main - pointers arithmetic
 *
 * Return: Always 0.
 */
int main(void)
{
   int *p;
   int a[2];
   int n;

   p = &amp;n;
   printf(&quot;p = &amp;n;\np: %p\n&quot;, p);
   printf(&quot;p + 1: %p\n&quot;, p + 1);
   printf(&quot;p + 2: %p\n&quot;, p + 2);
   printf(&quot;p + 10: %p\n&quot;, p + 10);
   /* possible since a is evaluated */
   /* as an int * in this context */
   p = a;
   printf(&quot;p = a;\np: %p\np + 1: %p\n&quot;, p, p + 1);
   return (0);
}
ubuntu@ip-172-31-63-244:~/julien$ gcc 20-main.c &amp;&amp; ./a.out
p = &amp;n;
p: 0x7ffd90a8cd2c
p + 1: 0x7ffd90a8cd30
p + 2: 0x7ffd90a8cd34
p + 10: 0x7ffd90a8cd54
p = a;
p: 0x7ffd90a8cd30
p + 1: 0x7ffd90a8cd34
</code></pre>

<p>Try to understand and draw the memory state at each step of the following program. Once you feel you understand everything, add some <code>printf</code>s, compile and run it to verify your hypothesis.  </p>

<pre><code>/**
 * main - Solve me
 *
 * Return: Always 0.
 */
int main(void)
{
   int a[5];
   int *p;
   int *p2;

   *a = 98;
   *(a + 1) = 198;
   *(a + 2) = 298;
   a[3] = 398;
   *(a + 4) = 498;
   p = a + 1;
   *p = 98;  
   p2 = a + 3;
   *p2 = *p + 1337;
   return (0);
}
</code></pre>

# Strings

<p>Of course, we can also create an array of chars. It would work exactly the same way.  </p>

<pre><code>ubuntu@ip-172-31-63-244:~/julien$ cat 12-main.c
#include &lt;stdio.h&gt;

/**
 * main - Creates an array of chars and prints it
 *
 * Return: Always 0.
 */
int main(void)
{
   char a[6];

   *a = &#39;S&#39;;
   *(a + 1) = &#39;c&#39;;
   *(a + 2) = &#39;h&#39;;
   a[3] = &#39;o&#39;;
   *(a + 4) = &#39;o&#39;;
   a[5] = &#39;l&#39;;
   printf(&quot;%c%c%c%c%c%c\n&quot;, a[0], a[1], a[2], a[3],
              a[4], a[5]);
   return (0);
}
ubuntu@ip-172-31-63-244:~/julien$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -o achar 12-main.c &amp;&amp; ./achar
School
ubuntu@ip-172-31-63-244:~/julien$
</code></pre>

<p>In this example, memory looks like this before exiting the program:  </p>

<p><img src="https://github.com/musfy/alx-low_level_programming/blob/master/digim/28d0f00e7e5012ead35e6bb6cf553baa930606d7.png" alt="" style="" />  </p>

<p>That would be one way to store strings, but this is not very efficient. If we wanted to store a very long text, imagine how much time would we spend storing each character of the string in our array!<br>
Fortunately, we can also use text in double quotes <code>&quot;</code>.  </p>

<pre><code>char a[7] = &quot;School&quot;;  
</code></pre>

<p>You probably noticed that in this example, we used an array of 7 characters to store a string of 6 characters. This is because in C, strings end with the char <code>&#39;\0&#39;</code>  (ascii value = 0). </p>

<p>In the above example, note that this statement will actually copy the string &ldquo;School&rdquo; into the variable <code>a</code>. Strings also have values in C: the address of their first character in memory: </p>

<pre><code>ubuntu@ip-172-31-63-244:~/julien/curriculum_by_julien/low_level_programming/pointers$ cat 13-main.c &amp;&amp; gcc 13-main.c &amp;&amp; ./a.out
#include &lt;stdio.h&gt;

/**
 * main - Prints the value of a string
 *
 * Return: Always 0.
 */
int main(void)
{
   char a[7] = &quot;School&quot;;

   printf(&quot;%s\n&quot;, a);
   printf(&quot;Value of the last char of a: %d\n&quot;, a[9]);
   printf(&quot;Value of a: %p\n&quot;, a);
   printf(&quot;Value of \&quot;School\&quot;: %p\n&quot;, &quot;School&quot;);
   return (0);
}
School
Value of the last char of a: 0
Value of a: 0x7ffe1a23cc50
Value of &quot;School&quot;: 0x400749
</code></pre>

<p>Memory would look like:  </p>

<p><img src="https://github.com/musfy/alx-low_level_programming/blob/master/digim/39dac20460d60d4ad1a47d639c350c218e94fb7f.png" alt="" style="" /></p>

<p>Since every string in C ends with a <code>&#39;\0&#39;</code> we do not need to know their size to use them. By knowing the address of the first character of strings (with a pointer to a char), C functions can easily print them using a loop, one character at a time, until they hit the character <code>&#39;\0&#39;</code>.  </p>

<p><strong>#cisfun #pointersarefun #everythingisawesome</strong></p>

<p><img src="https://github.com/musfy/alx-low_level_programming/blob/master/digim/blown-mind-explosion-gif.gif" alt="" style="" />  </p>

<p><strong><em>BONUS</em></strong></p>

<p>Our memory templates:</p>

<ul>
<li><a href="https://github.com/musfy/alx-low_level_programming/blob/master/digim/5b15142e4c3fb2a321fecb8da3f604348c451cd4.xlsx" title="Memory template.xlsx" target="_blank">Memory template.xlsx</a></li>
<li><a href="https://github.com/musfy/alx-low_level_programming/blob/master/digim/5b15142e4c3fb2a321fecb8da3f604348c451cd4.zip" title="Memory template.ods" target="_blank">Memory template.ods</a></li>
</ul>

</div>
