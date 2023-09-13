void solve() {
int n, k;
cin >> n >> k;
vector<int> a(n);
for(int i = 0; i < n; i++) {
cin >> a[i];
}
// declare variables
int mxSum = 0; // max sum of all the subarray till now
int sum = 0; // it will store the sum of current window
auto add = [&] (int idx) {
sum += a[idx];
};
auto remove = [&] (int idx) {
sum -= a[idx];
};
auto updateAns = [&] () {
mxSum = max(mxSum, sum);
};
for(int ind = 0; ind < n; ind++) {
int new_end = ind;
int old_start = ind - k;
// adding the new element to the window
add(new_end);
// remove the last element from the window only if window's

if(old_start >= 0) {
remove(old_start);
}
// if the window length >= k then update the ans
if(new_end >= k - 1) {
updateAns();
}
}
cout << mxSum << endl;
}

//-----------------------------------------------------------------------------------------------------------

void solve() {
int n, k;
cin >> n >> k;
vector<int> a(n);
for(int i = 0; i < n; i++) {
cin >> a[i];
}
vector<int> ans;
queue<int> q;
for(int ind = 0; ind < n; ind++) {
int new_end = ind;
int old_start = ind - k;
if(a[new_end] < 0) {
q.push(new_end);
}
if(old_start >= 0) {
if(!q.empty() && q.front() == old_start) {
q.pop();
}
}
if(new_end >= k - 1) {
int first = q.empty() ? 0 : a[q.front()];
ans.push_back(first);
}
}
for(auto it : ans) {
cout << it << " ";
} cout << endl;
}

//-----------------------------------------------------------------------------------------------------------

void solve(int testCase) {
int n, k;
cin >> n >> k;
vector<int> a(n);
for(int i = 0; i < n; i++) {
cin >> a[i];
}
oset<pair<int,int>> st;
vector<double> ans;

auto getMedian = [&] () {
int middle1 = st.find_by_order(k / 2)->first;
int middle2 = st.find_by_order(k - 1 - k / 2)->first;
return (middle1 + middle2) / 2.0;
};

for(int ind = 0; ind < n; ind++) {

int new_end = ind;
int old_start = ind - k;

st.insert({a[ind], ind});
if(old_start >= 0) {
// dbg(a[old_start], old_start);
st.erase(st.find({a[old_start], old_start}));
}

if(new_end >= k - 1) {
double median = getMedian();
// dbg(st);
ans.push_back(median);
}
}

for (auto it : ans) {
cout << it << " ";
} cout << endl;
}

//-----------------------------------------------------------------------------------------------------------

void solve() {
int n, k;
cin >> n >> k;
vector<int> a(n);
for(int i = 0; i < n; i++) {
cin >> a[i];
}
// initializing the necessary
vector<int> ans;
multiset<int> st;
for(int ind = 0; ind < n; ind++) {
int new_end = ind;
int old_start = ind - k;
// adding value
st.insert(a[new_end]);
// removing
if(old_start >= 0) {
st.erase( st.find(a[old_start]) );
}
// updating
if(new_end >= k - 1) {
int largest = *st.rbegin();
ans.push_back(largest);
}
}
for(auto it : ans) {
cout << it << " ";
} cout << endl;
}

//-----------------------------------------------------------------------------------------------------------

void solve() {
int n, k;
cin >> n >> k;
vector<int> a(n);
for(int i = 0; i < n; i++) {
cin >> a[i];
}
// declare variables
vector<int> ans;
deque<int> deq;
auto add = [&] (int idx) {


auto add = [&] (int idx) {
while(!deq.empty() && a[deq.back()] <= a[idx]) {
deq.pop_back();
}
deq.push_back(idx);
};
auto remove = [&] (int idx) {
if(!deq.empty() && deq.front() == idx) {
deq.pop_front();
}
};
auto updateAns = [&] () {
// dbg(deq);
int largest = a[deq.front()];
ans.push_back(largest);
};
for(int ind = 0; ind < n; ind++) {
int new_end = ind;
int old_start = ind - k;
// adding the new element to the window
add(new_end);
// remove the last element from the window only if window's
if(old_start >= 0) {
remove(old_start);
}
// if the window length >= k then update the ans
if(new_end >= k - 1) {
updateAns();
}
}
for(auto it : ans) {
cout << it << " ";
} cout << endl;
}