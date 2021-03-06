<h1 class="gap">0x00. Lockboxes</h1>
<div class="well clean" id="project-description">
  <h2>Requirements</h2>

<h3>General</h3>

<ul>
<li>Allowed editors: <code>vi</code>, <code>vim</code>, <code>emacs</code></li>
<li>All your files will be interpreted/compiled on Ubuntu 14.04 LTS using <code>python3</code> (version 3.4.3)</li>
<li>All your files should end with a new line</li>
<li>The first line of all your files should be exactly <code>#!/usr/bin/python3</code></li>
<li>A <code>README.md</code> file, at the root of the folder of the project, is mandatory</li>
<li>Your code should be documented</li>
<li>Your code should use the <code>PEP 8</code> style (version 1.7.x)</li>
<li>All your files must be executable</li>
</ul>
</div>

<h2 class="gap">Tasks</h2>
<div data-role="task3764" data-position="1" id="task-num-0">
	<div class="panel panel-default task-card " id="task-3764">
		<div class="panel-heading panel-heading-actions">
			<h3 class="panel-title">
			0. Lockboxes
			</h3>
		</div>
		<div class="panel-body">
			<p>You have <code>n</code> number of locked boxes in front of you.
Each box is numbered sequentially from <code>0</code> to <code>n - 1</code> and each box may contain keys to the other boxes. </p>
	<p>Write a method that determines if all the boxes can be opened.</p>
	<ul>
	<li>Prototype: <code>def canUnlockAll(boxes)</code></li>
	<li><code>boxes</code> is a list of lists</li>
	<li>A key with the same number as a box opens that box</li>
	<li>You can assume all keys will be positive integers
	<ul>
	<li>There can be keys that do not have boxes</li>
	</ul></li>
	<li>The first box <code>boxes[0]</code> is unlocked</li>
	<li>Return <code>True</code> if all boxes can be opened, else return <code>False</code></li>
	</ul>
	<pre><code>
			carrie@ubuntu:~/0x00-lockboxes$ cat main_0.py
			#!/usr/bin/python3

			canUnlockAll = __import__('0-lockboxes').canUnlockAll

			boxes = [[1], [2], [3], [4], []]
			print(canUnlockAll(boxes))

			boxes = [[1, 4, 6], [2], [0, 4, 1], [5, 6, 2], [3], [4, 1], [6]]
			print(canUnlockAll(boxes))

			boxes = [[1, 4], [2], [0, 4, 1], [3], [], [4, 1], [5, 6]]
			print(canUnlockAll(boxes))

			carrie@ubuntu:~/0x00-lockboxes$
			</code></pre>

			<pre><code>carrie@ubuntu:~/0x00-lockboxes$ ./main_0.py
			True
			True
			False
			carrie@ubuntu:~/0x00-lockboxes$
</code></pre>
		</div>
		<div class="list-group">
			<!-- Task URLs -->
			<!-- Github information -->
			<div class="list-group-item">
				<p><strong>Repo:</strong></p>
				<ul>
					<li>GitHub repository: <code>holbertonschool-interview</code></li>
						<li>Directory: <code>0x00-lockboxes</code></li>
						<li>File: <code>0-lockboxes.py</code></li>
				</ul>
			</div>
		</div>
	</div>
</div>
</div><!-- /.modal-content -->
</div><!-- /.modal-dialog -->
</div>