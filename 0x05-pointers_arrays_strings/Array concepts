<p>Read this page, write down and test all the examples (do not copy-paste!).</p>

<h2>Pointers</h2>

<p><img src="/images/contents/low_level_programming/projects/pointers.jpg" alt="" style="" /><br>
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

<p><img src="/images/contents/low_level_programming/projects/char_c_declaration.png" alt="" style="" />  </p>

<p>In this example, we simply declare a variable <code>c</code> of type <code>char</code>. The address of <code>c</code> is <code>8</code>. At this stage, you have not assigned a value to your variable <code>c</code>. So you do not know its value. It depends on what this memory address was used for before. You should never assumed that it is 0.  </p>

<pre><code>char c;  

c = &#39;H&#39;;  
</code></pre>

<p>When we assign the value <code>&#39;H&#39;</code> to <code>c</code>, then <code>&#39;H&#39;</code> is stored at <code>c</code>&lsquo;s address.  </p>

<p><img src="/images/contents/low_level_programming/projects/char_c_H.png" alt="" style="" />  </p>

<p>But you know that a byte can only store numbers. So actually, the byte will not hold exactly the letter <code>&#39;H&#39;</code>, but its ascii code, which is <code>72</code> (man ascii). So it really looks like this in memory:  </p>

<p><img src="/images/contents/low_level_programming/projects/char_c_72.png" alt="" style="" />  </p>

<p>Since integers are stored within four bytes of memory, the same example with an <code>int</code> variable would look like this:  </p>

<pre><code>int n;  

n = 98;  
</code></pre>

<p><img src="/images/contents/low_level_programming/projects/int_n_98.png" alt="" style="" />  </p>

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

<p><img src="/images/contents/low_level_programming/projects/p.png" alt="" style="" />  </p>

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

<p><img src="/images/contents/low_level_programming/projects/p_n.png" alt="" style="" />  </p>

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

<p><img src="/images/contents/low_level_programming/projects/p_n.png" alt="" style="" />  </p>

<ul>
<li><code>*p = 402;</code>: equivalent to <code>n</code> = <code>402</code>, since <code>p</code> == <code>&amp;n</code>. Now <code>*p</code> == <code>402</code> so <code>n</code> == <code>402</code>. </li>
</ul>

<p>This is what it looks like after this statement in memory:  </p>

<p><img src="/images/contents/low_level_programming/projects/p_n_402.png" alt="" style="" />  </p>

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
