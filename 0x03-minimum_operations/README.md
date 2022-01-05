<h1>0x03. Minimum Operations</h1>
<div class="panel-body">
    <p>In a text file, there is a single character <code>H</code>. Your text editor can execute only two operations in this file: <code>Copy All</code> and <code>Paste</code>. Given a number <code>n</code>, write a method that calculates the fewest number of operations needed to result in exactly <code>n</code> <code>H</code> characters in the file.</p>

<ul>
<li>Prototype: <code>def minOperations(n)</code></li>
<li>Returns an integer</li>
<li>If <code>n</code> is impossible to achieve, return <code>0</code></li>
</ul>

<p><strong>Example:</strong></p>

<p><code>n = 9</code></p>

<p><code>H</code> =&gt; <code>Copy All</code> =&gt; <code>Paste</code> =&gt; <code>HH</code> =&gt; <code>Paste</code> =&gt;<code>HHH</code> =&gt; <code>Copy All</code> =&gt; <code>Paste</code> =&gt; <code>HHHHHH</code> =&gt; <code>Paste</code> =&gt; <code>HHHHHHHHH</code></p>

<p>Number of operations: <code>6</code></p>

<pre><code>carrie@ubuntu:~/0x03-minoperations$ cat 0-main.py
#!/usr/bin/python3
"""
Main file for testing
"""

minOperations = __import__('0-minoperations').minOperations

n = 4
print("Min # of operations to reach {} char: {}".format(n, minOperations(n)))

n = 12
print("Min # of operations to reach {} char: {}".format(n, minOperations(n)))

carrie@ubuntu:~/0x03-minoperations$
</code></pre>

<pre><code>carrie@ubuntu:~/0x03-minoperations$ ./0-main.py
Min number of operations to reach 4 characters: 4
Min number of operations to reach 12 characters: 7
carrie@ubuntu:~/0x03-minoperations$
</code></pre>

</div>