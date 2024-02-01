<h2><a href="https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag">No companies found for this problem</div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px; --darkreader-inline-fill: #4aa0f2;" data-darkreader-inline-fill=""><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>2966. Divide Array Into Arrays With Max Difference</a></h2><h3>Medium</h3><hr><div><p>You are given an integer array <code>nums</code> of size <code>n</code> and a positive integer <code>k</code>.</p>

<p>Divide the array into one or more arrays of size <code>3</code> satisfying the following conditions:</p>

<ul>
	<li><strong>Each</strong> element of <code>nums</code> should be in <strong>exactly</strong> one array.</li>
	<li>The difference between <strong>any</strong> two elements in one array is less than or equal to <code>k</code>.</li>
</ul>

<p>Return <em>a </em><strong>2D</strong><em> array containing all the arrays. If it is impossible to satisfy the conditions, return an empty array. And if there are multiple answers, return <strong>any</strong> of them.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,3,4,8,7,9,3,5,1], k = 2
<strong>Output:</strong> [[1,1,3],[3,4,5],[7,8,9]]
<strong>Explanation:</strong> We can divide the array into the following arrays: [1,1,3], [3,4,5] and [7,8,9].
The difference between any two elements in each array is less than or equal to 2.
Note that the order of elements is not important.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1,3,3,2,7,3], k = 3
<strong>Output:</strong> []
<strong>Explanation:</strong> It is not possible to divide the array satisfying all the conditions.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>n</code> is a multiple of <code>3</code>.</li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>5</sup></code></li>
</ul>
</div>