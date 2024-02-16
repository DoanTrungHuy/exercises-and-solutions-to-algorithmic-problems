<h2><a href="https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag" style="background-color: rgba(0, 10, 32, 0.05); --darkreader-inline-bgcolor: rgba(0, 8, 26, 0.05);" data-darkreader-inline-bgcolor=""><div>Amazon</div><div class="companyTagsContainer--tagOccurence">5</div></div><div class="companyTagsContainer--tag" style="background-color: rgba(0, 10, 32, 0.05); --darkreader-inline-bgcolor: rgba(0, 8, 26, 0.05);" data-darkreader-inline-bgcolor=""><div>Expedia</div><div class="companyTagsContainer--tagOccurence">4</div></div><div class="companyTagsContainer--tag" style="background-color: rgba(0, 10, 32, 0.05); --darkreader-inline-bgcolor: rgba(0, 8, 26, 0.05);" data-darkreader-inline-bgcolor=""><div>Booking.com</div><div class="companyTagsContainer--tagOccurence">3</div></div><div class="companyTagsContainer--tag" style="background-color: rgba(0, 10, 32, 0.05); --darkreader-inline-bgcolor: rgba(0, 8, 26, 0.05);" data-darkreader-inline-bgcolor=""><div>Salesforce</div><div class="companyTagsContainer--tagOccurence">2</div></div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px; --darkreader-inline-fill: #4aa0f2;" data-darkreader-inline-fill=""><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>1481. Least Number of Unique Integers after K Removals</a></h2><h3>Medium</h3><hr><div><p>Given an array of integers&nbsp;<code>arr</code>&nbsp;and an integer <code>k</code>.&nbsp;Find the <em>least number of unique integers</em>&nbsp;after removing <strong>exactly</strong> <code>k</code> elements<b>.</b></p>

<ol>
</ol>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input: </strong>arr = [5,5,4], k = 1
<strong>Output: </strong>1
<strong>Explanation</strong>: Remove the single 4, only 5 is left.
</pre>
<strong class="example">Example 2:</strong>

<pre><strong>Input: </strong>arr = [4,3,1,1,3,3,2], k = 3
<strong>Output: </strong>2
<strong>Explanation</strong>: Remove 4, 2 and either one of the two 1s or three 3s. 1 and 3 will be left.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr.length&nbsp;&lt;= 10^5</code></li>
	<li><code>1 &lt;= arr[i] &lt;= 10^9</code></li>
	<li><code>0 &lt;= k&nbsp;&lt;= arr.length</code></li>
</ul></div>