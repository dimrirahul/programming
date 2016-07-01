#include <iostream>
#include <vector>

using namespace std;

using StrVector = vector<string>;
using Str = string;
const Str END_CERT = "-----END CERTIFICATE-----";
StrVector parse(const Str& certChain) {
    StrVector out;
    size_t pos = 0, prevPos = 0;
    while ((pos = certChain.find(END_CERT, prevPos)) != Str::npos) {
        pos += END_CERT.size();
        cout << "DEBUG: prevPos=" << prevPos << " pos=" << pos << "\n";
        Str cert = certChain.substr(prevPos, pos - prevPos);
        out.push_back(cert);
        prevPos = pos;
    }
    return out;
}

static size_t countAllOccurencesOfSubstr(const Str& haystack, const Str& needle) {
    size_t pos = 0, count = 0;
    while ((pos = haystack.find(needle, pos)) != Str::npos) {
        count++;
        pos += needle.size();
    }
    return count;
}

Str getHaystack() {
    Str str = "-----BEGIN CERTIFICATE-----\
               MIICdTCCAd4CCQDlsvzBaZf1RjANBgkqhkiG9w0BAQUFADB/MQswCQYDVQQGEwJV\
               UzELMAkGA1UECAwCQ0ExFjAUBgNVBAcMDVNhbiBGcmFuY2lzY28xDzANBgNVBAoM\
               BlNwbHVuazEXMBUGA1UEAwwOU3BsdW5rQ29tbW9uQ0ExITAfBgkqhkiG9w0BCQEW\
               EnN1cHBvcnRAc3BsdW5rLmNvbTAeFw0xNTA1MTExOTUxMzdaFw0yNTA1MDgxOTUx\
               MzdaMH8xCzAJBgNVBAYTAlVTMQswCQYDVQQIDAJDQTEWMBQGA1UEBwwNU2FuIEZy\
               YW5jaXNjbzEPMA0GA1UECgwGU3BsdW5rMRcwFQYDVQQDDA5TcGx1bmtDb21tb25D\
               QTEhMB8GCSqGSIb3DQEJARYSc3VwcG9ydEBzcGx1bmsuY29tMIGfMA0GCSqGSIb3\
               DQEBAQUAA4GNADCBiQKBgQDJmb55yvam1GqGgTK0dfHXWJiB0Fh8fsdJFRc5dxBJ\
               PFaC/klmtbLFLbYuXdC2Jh4cm/uhj1/FWmA0Wbhb02roAV03Z3SX0pHyFa3Udyqr\
               9f5ERJ0AYFA+y5UhbMnD9zlhs7J8ucub3XvA8rn79ejkYtDX2rMQWPNZYPcrxUEh\
               iwIDAQABMA0GCSqGSIb3DQEBBQUAA4GBAFd9dzyyb2wnlDy3tlFVH2BUXdJZPKIC\
               E3VyMsPTNhXDq7ESVWBLJeUQh6uJ1A3QyLrtTqG/1h62vvP+UxAw4THZ4g3a2i65\
               3T1q78dhq1cKneOuE83Te/fREH54QokzrnAXoz+v/aGJkzjEpSEwrWUwLA1koE8I\
               /0XFEwxWbEbt\
               -----END CERTIFICATE----- \
               -----BEGIN CERTIFICATE-----\
               MIICdgIBADANBgkqhkiG9w0BAQEFAASCAmAwggJcAgEAAoGBAMmZvnnK9qbUaoaB\
               MrR18ddYmIHQWHx+x0kVFzl3EEk8VoL+SWa1ssUtti5d0LYmHhyb+6GPX8VaYDRZ\
               uFvTaugBXTdndJfSkfIVrdR3Kqv1/kREnQBgUD7LlSFsycP3OWGzsny5y5vde8Dy\
               ufv16ORi0NfasxBY81lg9yvFQSGLAgMBAAECgYEAnOw8lMcEqSVs6dfFZSztm6dN\
               xrYrOnTgoKV3F3bzSV5bJMnUzsseJVeImJzT6gTPqYtNGhvk+1R20CkKVQfDDQMz\
               OZvnG6l/RlPdAsqmicZ6JD+sAGvfYMBiT1Ijw2IfaimbGAbTNqeI3VDsbtJ/CjOt\
               HNo7OoENrdsTIqCLkzECQQD6YLV6TezXzEbZtTDdq060WDn0feJfRtOfLfFsCtlh\
               ZW37fUmX/tVpOv/n8JOWa7moo+PBpxuPQQlbVbMlOPvjAkEAziCj9Hv3c2sIonvl\
               Km9rPhDgeeIA50TIR5oj3H96Hr0utHPrr7372bNscwDuiIogMK/WwkthESL0Vp8h\
               DpCEOQJAI7WVTHs+s0x0MmqwLH1ZPUl0ApXNqm8MkaBY1WL6u/ReakblLyNuRpLe\
               mrLqKcL1eMLfIeh2esj4z6j6Yu2spwJAOh0vvGUa/dpmY9EEajNhi+0cLKDQWmOl\
               B7Loe2khV/tEaLHp9/FbSSRx5faUScCPlMpuhPbVlgxB0Q4qNr392QJAEaXM/YS2\
               cQ5l+2NPl+rGkGrLNLW8gdP7tr6RQJ9+jPjkaI7W7gH8ZoXU/FlkVfXMnRZrqhnn\
               UwO+tFeZjZgLkQ==\
               -----END CERTIFICATE-----";
    return str;
}

const Str BEGIN_CERT = "-----BEGIN CERTIFICATE-----";
Str makeStr() {
    Str retStr;
    retStr = BEGIN_CERT + "text1" + END_CERT +
        BEGIN_CERT + "text2" + END_CERT +
        BEGIN_CERT + "text3" + END_CERT +
        BEGIN_CERT + "text4" + END_CERT +
        BEGIN_CERT + "text5" + END_CERT;
    return retStr;

}
int main(int argc, char **argv) {
    /*
    Str str = makeStr();
    StrVector strVector = parse(str);
    for (auto it : strVector) {
        cout << it << "\n";
    }
    */
    size_t begCertCount = countAllOccurencesOfSubstr(getHaystack(), BEGIN_CERT);
    size_t endCertCount = countAllOccurencesOfSubstr(getHaystack(), END_CERT);
    cout << "BegCOunt = " << begCertCount << " endCertCount = " << endCertCount << "\n";
    return 0;

}
