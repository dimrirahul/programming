#include <iostream>
#include <thread>
#include <vector>
#include <set>
#include <queue>
#include <future>

using namespace std;

using VS = vector<string>;
using Url = string;
using VUrl = vector<Url>;
using SUrl = set<Url>;


VUrl getPageAndParseLinks(const Url& url) {
        return VUrl();
}


SUrl getAllReachableLinks(const Url& baseUrl, int maxAsyncJobs = 5) {
        queue<Url> q;
        SUrl urlSet;

        q.push(baseUrl);
        while (!q.empty()) {
                int asycJobs = 0;
                vector<future<VUrl>> pendingResults;
                while (!q.empty() && asycJobs < maxAsyncJobs) {
                        Url url = q.front();
                        q.pop();
                        if (urlSet.find(url) != urlSet.end()) {
                                continue;
                        }
                        urlSet.insert(url);


                        asycJobs++;
                        future<VUrl> pendingResult = async(getPageAndParseLinks, url);
                        pendingResults.emplace_back(move(pendingResult));
                }

                //wait for jobs to finish.
                for (auto& it: pendingResults) {
                        VUrl childPages = it.get();
                        for (auto& childPage: childPages) {
                                q.push(childPage);
                        }
                }
        }
        return urlSet;
}

int main() {
        SUrl sUrl = getAllReachableLinks("http://somedomain.com/base_url");
        (void) sUrl;
        return 0;
}


