// Author: envy
// Problem: Problem 1. Moocast from USACO - USACO 2016 December Contest, Gold
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=669
// Limits: 4000 ms, 256 MB
// Attempted: 2021-09-10 17:47:17 EST

#ifndef LOCAL
#define debug(...) 0
#include <bits/stdc++.h>
#else
#include "C:\programmingfunnyxd\debug.cpp"
#include "C:\programmingfunnyxd\includeordie.h"
#endif
using namespace std;
inline namespace readio { const int BSZ = 1<<15; char ibuf[BSZ]; int ipos, ilen;char nc() {if (ipos == ilen) {ipos = 0; ilen = fread(ibuf,1,BSZ,stdin);if (!ilen) return EOF;}return ibuf[ipos++];}
template<class T> void ri(T& x) {char ch; int sgn = 1;while (!isdigit(ch = nc())) if (ch == '-') sgn *= -1;x = ch-'0'; while (isdigit(ch = nc())) x = x*10+(ch-'0');x *= sgn;}
template<class T> void rc(T& x){ x = nc();while(isspace(x))x = nc();}template<class T, class... Ts> void ri(T& t, Ts&... ts) {ri(t);ri(ts...);}
template<class str>void rs(str& x) { char ch; while (isspace(ch = nc()));do { x += ch; } while (!isspace(ch = nc()) && ch != EOF);}}
template<typename T> void max_self(T& a, T b){a = max(a,b);}template<typename T> void min_self(T& a, T b){a = min(a,b);}
struct minsecond{bool operator()(pair<int,int> a, pair<int,int> b){return a.second > b.second;}};
// template<typename T> pow(T a,T b,T m){int ans=1;while(b){if(b&1){ans=(ans*a)%m;}b/=2;a=(a*a)%m;}return ans;}
template<typename T> using minpq = priority_queue<T, vector<T>, greater<T>>;template<typename T> using maxpq = priority_queue<T>;
typedef priority_queue<pair<int,int>, vector<pair<int,int>>, minsecond> secondpq;


/*
 
                                                             ..::rriivr7::..
                                                  ..::i::i:......::irirvL7Js1UIUK5v:
                                              iv7i::..              .......:.:.::71gBBb:
                                          .sbP7.                      .::..::::::...:rKMRRU:.
                                       .vIs7.                      .   ..:...::i::::.:.:iUPKSIsLi.
                                     .25r                         . .    .:...::i:i::::::::rvUbYvISu7.
                                   .2qr.                       . .   . .  .:....:i:i:::::::::.:P1::rsKS2i
                                  1qr                                 .     ...  .::i:::::::ii. id7.::i7uU2r
                               :YL:                          .     . . . . . ...  .:::ii:i:i:ir: .gK:::::::L21i
                            .rv:.                               . .   . . ..  .:.   :..:r:::::i.   ZBv.::ii..:JE2.
                          .77.                            ..     . .   . . ..  :i    .  .r:i::i:    uBq:.iii::..rI2r
                        isr         .                 .     .     . . . .       r:  . .  .ri::iii.  .iBgi.:ii.:::.:r7ri
                      iui          .       . .       .       .   .   . . .      .v.  ...  .ri::iir:..::QPv::ii::::::. .v7.
                    iUi     .     .       .                 .   .    .. ...      i7.  ...  ir:::i:iiii:rQS1i:ii.::::i.  .7L.
                  :Si    . .     ..      .:          .     ..    .   . . .....   :7i ......:iLi::::::i:.JguI7::i.::::ii:   rr
                :u7   . . .     .:  .    .i              . .. . . . ... ... ...   27. ...  .:r2.::::::i::KEJSL:::.::::::i:. :u:
               2u    ... . .   .:.   .   ::    .   .       :.  . . ..... .......  7U:. .... .iPi.::::::i:iZKs5ui::.::::::::irIP:
             7K.  ... . .    .:::     .  ri   .    .. . . .:: . ... ... ..... .   :Ei:  . .  :I7.::::::ii.vDUs5Ui::..:::r777vr7i
           .5r   ..... .   ..:::   . .   Y:  . .   :.  .  .i:  ...  :. . ... ..:   gvi. .. . .Lv.:::::::i::Xdj1PZJ7r7YL7i:.
          JI. ....... .   .::.:.  . .    v:       .:r .   :ri ....  i . ... . .i.  Xq:r ::    7P..::::::i::rbKUULrLL.
        .qr  ....... .  .i::.:7. . .     1..  ..  .rr  .  .Jr  ... .r. ..... . ii  YE7::.U.   :P:.:i:::::i:iXb:
       75.  .......   .:i::::i7 . . .    1:.  ..  .77   ..:Sr  :.  .7. ....... i7  rRu:i.1r   :X7 :::::::ii.XP5      .:
      Uv   .......  .:ii::::.L.  ... .   2:.   . ..Is   .::M:  i   .r. .....   7L: :Eqr:.7u:  .I1 .::::::ir:rdd. :Ss. ..
    .S: ... ...   .:rii::::::Y  . . . . .2:.  .. .iKu   ::r5. .r..:iY. ...... .rIi .JP1:iiPr. .7b .:::::::rr:PqI .i.vi
   iu. ... . . . .:r:i:iiiirrv ... . .  .S:.  .: .vLr   :i2Uv.iIiiirs. : ...  :i57 riKd7i7gS: i1Q. .::::::i1.q5Zr:.  .Yi
  ir  . .      .irrr7v7rr:7Y17  . ... . .Xi.  i. .2.7.:iL7P.s  U:  :r: :. ..  r:XY.i.:gr..Pu:  rQZqi..:::::2:vgUd. ..  :r
.7E7...:::::.v11jsv7:.     ir:  .. . .   Zr.  i. :Kis: .:r7 7. 25  rrr r. .. .iiSU.7. PS:.XRr  iEr.JYr.::::j7iBsZ. ..   i:
..s7i::... .sv:   7v    .  .U:  .......  b1.  7:7.: r. .is: i: YB. iiS.r. .  .iiZ2:L. iQi.7qK  :du  .r:::.:rIiBubi .i.ri.
          .:  ..  D.   ::...qr . ......  Pq. is.7. .i: :r1...L JPL i:P.r.   :.:755iv.  MJ.viZ..iKP ...:::::i2sQPuI....
         .Q.   . :q :r...i: si  ... ...  Yg: :i.P.  :7 :L7   i.L277::b:i:  .r.:LLSLL   :M.v:ri.:5M  ..::::::uJQDvQY
           17    v2sM7 ...  iv ... ...   vQ7 ::vU  ..L :1:    v7I.U::Zri:  7i.:uiPI7    dr7i .i:Ug  .:.i:::.vjgQ7bR
           .u    1PuDv  ..  i7  ... ...  :BJ ::b:.   i :X::ii.SJd r7:Pv:: i7:.rs.qZ:    :jri  X:jg. ::.::::.jjZQuYBv
            X.   uIsD1 ... rB: . ..  ... .QX:.vX     s:ii     .Zg. 5:PY::irr:.Ji Zd  ..  Lrr  .77R. :i.::::.2SqB2LPK
            .B  .vjsPE     QBr  ...   ..  gEr.P:.rr  :77ursv:  :B7 :5SI.iiir..K .Qu  .i7JPUgDgPMKD. ::.::::.IqPBK75Yr
             id rvr2SEi:  .QBI   ..   ..  7Br:DLi:.rjgEqBBBBQL  LQ  1gS::iir 1i  B  .MBBBBPBBBBBBM. ::.:::::rZXBq7bid
              ruLiiUIu7ii.1ZBZ   ..    ..  BuU7 i5QBBQRgBBBQ7uu: sr  gD::ii:r7  r2 :MBBQBQBbYY1IBQv ::::i::::PbQZ7P:5r
               RP:.jKvJ:irYbQB   ..    ..  KqUJRBQRBQBBBs      .  :  .Qr:iiL.   L  SQB17r2r      U2i.:::ii:::UbQELPiiQ
              .2d:.rEiS::urPQBi ....   ..  .QZBMMBBDI7sL   .:         JS:rS:    :  Bguv7u52UjjB: jrr::::ii::vLdMDvbi:u7
              vvv:::K:2riS.XQBv  ..i   ...  PBQQBBqrrsJ552UBj          K7s        iBri:EX.i: DB  Pi:::::ii:.jsXQZJPi. g
              I7L:::q:7uIr.KBBP   :: .  ..  igrEBrssLIur7..B7          si         .Q  .KS....BK  Si.:::.ii:.S22QZJb:  jL       ..
     ::::.   :UL7::iS::P7::2BBQ   ii . ...  .S SPii:.Bq....B.                      X:       Yg   2i:::::ii:.5Z7BqKg    R      ::.
     :::i:   v71r::i5:i:irr7.QB   7:  .....  ur Z  ...... :U                        :.     u     2i::::.:7i.SBiQqZB  . Ys    ::..
       ..    v uii:vU:r77i v iB.  7i .....   .P .d        1.                         .   :uj..   5i::::::1i.UBiEdQQ. .  M    :..
            ii Ji::YUrr:.  r. 7:i 7i ......   :: ..:.    vY..              .          ....  ....:Ji::::.:5v 2B7uBDqi .. uj   ::..
            j .I:i:2:.   . vi  rv:rr ...  .i   rr  ....... ....                       ......... .P:::i:..PI YBuvBK2v ... R    .:.
           .u :u::iP. .... rJ  rU:ii. ...  rv.  rr  ...........                       ......... :2::ii:..KD 7BPrBL25  .. rL     .
           r: i1..iK  .... :Y  .X:ir:  ..  .77r. :7. .........                         ... ...  .I:iii::.bM:YBgrSYjg  ..  Z
           U  Yv  r5 .......I   KiiJr:  ..  rr7Yi .v: ..... .                                   Su::i::i.PQrqQQivjUg: .   ur
          i7  S7  75 .......5   r1:dri.  .  .7:7:r::i:                   .                     :Br:iii:7 gR7KQQi7XrP7 .    g
          U.  K:  7J ...... 5    KiqX:r.  .  :7v7 .:i77.                 i:                  .Iv7riii:77.QRrdQD:vq.iP      5i
         .v  :S.  r1 ...... I:   sL2E7:r.  .  :vEi.   .r..                                .iUj  rr:i::ur.BZ7DQUivX..P      .b
         7.  iS   vr ...... vi    EuqP:i7.  .  .q::rri:                               .i55v.    5ii:::P.rBg7BSjius..P       g.
         u . sJ   7:   .... :s    ug227:i7.  . ..     ...:::                       :7jLr.       Ki:i:vb.vPR2EL1r1r..1.      r2
  .     i:   2r . Y.     ....2     QPv.u:i7:  . 7v         7uU5uj::...... .::iqIYRqi            M:i::KS.i.BXuY2r2...vr       R
:.::.   u    K.   u.       . b     :Bg :2:iri    P     .i22uvrrYBi:ii7v2USsvi7B5rv7vL7.        iQ:::7B7s  BKvuusY.::i5       d:
:.::.   u   .X    2          1.     vB: r5:iri.  :r :7v7i....:iivg. ...   .   d:.   ..rsr.     :E.:.ED7i .BujJ1Ir.::.K       :q
....   ri   .U   .U          Ji      uQ  rKiirr:  Kv.    ..    . iE. ..7sr:: Y:  ...     ..7   .U:.YRK.  iQJJu1X..:: 5.       R
       s.   :v  . U          :s       ru  iPi:iri .i      .....   .gv:::..::vb  ...      vLr1  r2.:MQ5   iZJjJSs..::.iJ       P.
       1    ii   .5           J            :Pi:iir.P         ..... :D       7i ..    .rdRKiiPr vv.PBS    :P1JUSr.:::..q       i2
      .7    v.   .X           I              Z7:ii:X1          .... :g.    .S      7ZPZ5:::i:K J:PBi     rbJjuX:.:::: b        E
      ii    s    :v           J             :YISi:::MMPS7.       ... rq    S    rBBE7.7s.ii.  quXq       Iq1J2u..:::. u7       S
      s.    X    :7           7            .7 .iUur.:JiDDZMPXi        rJ  :. :dBBU:    j::r.  qM         sPJu57.::::: :Qrri... u.
      L     J    rr           r.           J     :JjrirE::rYQBBQuiri.  v: XvMBBBJri.   7::i  7L7:        SX1uXi.::::.  M  .ii:.i.
      s    .7    ii           :.          7:  .   .iriiK. ...sBBBBBBBgPZ5uBQX7LvJUKqSsv2S7i  .  K.       XKJUU:.::::.  qi
     .v    r:    7.           ..         :r  . .  .i:.:v :7UuJu1vLvvvSPBPSggUuvvLsYjs7i::UE:    .E       S5u1J::::::.  vq
     :i    v.    v.           ::         U  .....  :iiJsr7vYJvLvLvLLXISRg7PM2I2vsLYLsLjs2Pi   .  :S      EIJ5r:i::::.  :g
     U.    u   . r            .:        J.  ...... .idS7v1sJvvvLvv7vvs2g:.rBJLvvvYvLsqMMLui: ...  77     M1u2i:i::::.. :q7
     2     u .   r            .:       i7   ... ... ::I2DgDKS1JvJjUu1UDY::iQg22jsvuIDPL..75.  ...  5.    g21U:iii::::..:vK
     7  ...r.: . uv           .r      .q   .......  .J. :iJEPEXI2S5SXdQr:iiRgMqS22IQ7 .ii.s  ....   P    gUIv::ri:::...:id
    .Srir.:ir:  ..:Is.        .5      P   ........ .iI. .:.i7dDKPPEbZgBr::rMZZQDdKZBE.::. r:  ...   :I   gI2r.:L7:::...:i17
          rLr: .   i7uUj:      2     2:  ..... .   :ij   .. LgDZbdbZgDRr::vBbPqZgQMPdM    .U   . ..  ui  d5Si::1r:::.. .irK
          17r.. . .ri::7Dgj.   7    Ls  ... ... .  .Ku  .  rBEZZDEgZKIg7i:uM2u21SX2vYXS    S:   ....  q  2Pu:::17:i:   .r:Z
          U7:.. . :7ii::.UZMPi:L   rR  ..... . ..  vR. .  .Bdq55UDPJsjdviiJgU5IXLv7YYuR7   iX  .....  .K ubJ.::2r:i: .  i:2r
          Ps..:   iiiii::J2ubq    .d. . ... . . . .ZL     QbX2uv7vY7v7q7: :gSIKsvvJLvrvP.   D:  . ...  ri:g7:::5Y:r: .. iiu2
         :Z1 :r  .rrii:::IjuUd    v  . . . ... .  :S:    PQIYvvYvYLJsjPY  .Q5KYvvUJY77vXi   L5.  . ...  r1Qr.::Ku:i: .  :7YP
         vZJ :7. .rii:i:iI1JUd   r: ... . ...... .rq. . :QP5IUUsJvvr7rSY:  Dg51SZP2vL77:  . .P:   ...    i:I7.i5Sii.  . i7j5.
         Pqs iri :riii::r5JujM. 7r . . ......... .sU   . .77v2UISg55L7Iji. KZXdu5::::::r.    Kri   ... ..  .UrrX57:i .  .Y117
         gK7 irr.:riiii:vIuJuE. 5   . ... . ...  :Pi  .  .:::..::dr21iuv: .. :2.K      .. .  YK:i   .  .7i.  rqq5J:i.  ..JXvJ
        .g57 rir:iiiii::Y2suJKSi   ... . ... .  .rP  ..          P :5ir:.... .1 D.       ... .Z:ii     .irr:  .bE5ir.  i ISJ5
        7bKi iiiiii:i:::u1uJuqB   . ..... . .   :j1  .. . . . .  d  Eri ..... u P:  . . ...   Uv:ii   .riiir.   UQv:: .r 25JK
        5qSi rii:i:i:i::U1JuqP.  ... . . . ... .:X.  ..  .....   g. Z7:...... v.5i   . . ...  .P.iir .riiiir     iD7: :r J2Ug
        KIK: ii:i:iii::i5juqK   .....   ... . .rrS  ...   .....  E. E7: ..:...r.57  . . . . .  Pi:iiiiiii:r.  .   .Su ir rKJB.
        dUS: riiiiiiii:r2UqP   . . .  .. ... .i:vr . ..    . ..  E: Is:..:. ..::Yj  .... . .   u2.:iii:iiri  . .    vX:i.:XjR.
        gjK..ii:i:7ii::r5Xd   ... .  .7i  . .ii:E   . .     . .  Pr qv:.:.  ..:i71  . . . ...  .Q:::i:i:ir. . . ...  :Ki:.buM:
       .ZsP: r:ii:7r:i.vKR   . . .   rrr.   ii:Z7  . ...   ... . X7 5u...   ...vrb   . . . ...  ID.::i:ii:   . ... .  ivr gUM:
       igYEr riii:J7:::JQ.  . . .   iiii:  :i:1M  . ..... .....  1s 1U..    ...rrZ  ... . ..... .QU:::i:i.  ..... .  7q:U Z1R:
       iZJSi.rii::vKr::gr  . . .   iri:ii.:i:sQ7   . ... ..... . YI rS..    ...7:Z   . . . . .   KgUi::i:r:  . .   i7.1r5 Q5R.
       iguI .ri:i.sIS::7           ri:iiii::j5D       . . .....  vg rS.     ...i:E. . . . .       Bu57::::r.      r:  .1q ISB.
       .DU5  rii::J2UJ:   .:::::...iii:i:::uJbP......    . ...   vD iR      .: r.R.  .....  .::ii:5qs5v:.::i   :iL.   .IP .ZQ
        MUq .vi:i:u11uIPYi::iiririr:i:i:::jujMi:rrL7vr7L: ... .  rg :Qi     ...7.P.   ...  2ri:..  EjsIs:.:iJXdL7vr:gZijd  BE
        dXX  Xii::J2JuSZ7PSji:...::::i::.LUsqq        .q   ...   ig :Iq.     :.i.X:  ... . 5:      1IYuXKuIP11vYY7: uQi5d :Bi
        XPb  iu:::u1jsZ7  :vXXD27::..::.rUJvR.        rv  . . .  :Q :JvK     :.r:U7 . . .  :X      :B5bDgdQLri:.    .Q1PP UQ
        :Rd   Ur::j2JJX.     :LgQQZXvi.:JjvSg........ u: . . ... ig.r7i1b    : r:Lj  ... .  K777sv77RPUi  sI         PSQ. Qi
         gg   .K::j1jsUuLi:.    .:L5ZQd5PIuEsrjvUu5UU77 . ... .  :M.7: .JE.  ..iv:q   . ...  .ii7rr:P.     :vr       uQj r:
         iBi   :2:L2JjJ2KBri7vi:.iriisbQRgQE.:ii:..      . ....  iZ.7i . iK  ..r7.E. ... . .     ...s:       :KQEZEgdZZ .
          KM    rsv2usus1d    ..:.:71 ... :P          . . . . . .ig.vi....iK. .iv Z:  ... . .        q        .MSU21PQ
           7     :bPJuss1D         1      vI...              .  .iE.L:.. ..iK: iL 27             .:rrBJ        M115EM
                  .qDuUSI2      :rs.     .RrLY2JJ7r::..         .:Z.5:..   .:1..K L5      .:r712SS2v:.E        ZqPqQ
                    7gPgqbYuSQ7::.       d:  ..:ir71j2u52JY7ri: .ib.S:..     . .b ibivJ1SbPqIYr:.     b.       ZB7.
                      vR72QPXB.         .S            .:iivrr7JYYvg.S: .......::d .qLiri:..           Xi       v.
                        : idgB          7.   . . . .            ::E.Sv:i:::i...:b  5r          .      7i
                            :1         iq .         .   . .     :iK qi::.     ..E: vZ     . .       :i7
                                         I7r77::..       .      :7u.P:iririvYQi:Iv iR.        .:i7UKDv
                                        :7  KI:rvvv7i::....... :iLIi:        I  .vrYQDr7r77:I7v7i..:vE
                                        5   u        JSii:7uIPULDDg:         2       ... .. j   ..   K:
                                       :r   J        J          q            2.             i   ....  S
                                       Y   i.        J          q .          q.             :.       .I7
                                       iii.7        .i          u            L.             r1.:riv7rr:.
                                        v:qdii:iii:sSJ7r:.     suri:.. .     Urr::::....... P:   .
                                       v. .rr7v7v77ri:r7jUdqri7i..:ii::ud.:ur..:iirrr2:.rrr..
                                      .Y   :ri:i:iii:i:iiL.v.......... r7  u .....   v
                                      L:  ..:ii:iiiiiiirY  v: ..... .  rv  s  .      7
                                      J  . ..:riii:i:ivv   Y:          rr  s         r
                                      L ......:ii:iiiv7    i7          i:  s        .r
                                      v  . ....iii:i77     .J          L:  j        .r
                                      J   ......iv:is       S          v:  J        ii
                                      7.:  .....:JiJ.       7:         v:  J        rr
                                      .7i.  ..:.::vr        .r         v:  L        i.
                                       1.:: .:::::.r         7         Y:  U   . .. s.
                                       .r :7:.:::i .         diiri7rir:Pi  XJirrrL2rg
                                        .  .r7::.7           1         7:  L        7
                                             .vr:ii          v         ::  v        L
                                               :7rv          v         i:  s        7
                                                 .sL         i.        ::  7        :
                                                   r.        r.        i:  :        :
                                        ..............:.:.:..s:   .... i7..j...... .q...:......
                               ....:.:::.:.................. Y7ri7sUI5SB7..Buj1IJs7iR........:.:::.:......
                       ...:.:.:.:.:..........................PY7YLsvvvSQ: :BdI211JI5Q...............:.:.:::::..
                      .i::.................................. gBBRgDMRBBBs iBQBBBQBBBM .......................::::
                                                             .:.:::::::i.           :                           .
*/

typedef long long ll; const ll INF = 1e18; const int MOD = 1e9+7;
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define print(x) cout<<x<<"\n"
#define mp(x,y) make_pair(x,y)
#define np(x) next_permutation(all(x))
#define F first
#define S second
#define sz(v) int(v.size())
#define bpop(x) __builtin_popcount(x)
#define fillarr(arr,n,am) fill(arr[0],arr[n],am)
#define readarr(arr) for(int &i: arr)ri(i);
#define readchararr(arr)for(int &i: arr)rc(i);
#define readgrid(arr, n, m)for(int i = 0; i < n; i++)for(int j = 0; j < m; j++)ri(arr[i][j]);
#define readchargrid(arr, n, m)for(int i = 0; i < n; i++)for(int j = 0; j < m; j++)rc(arr[i][j]);
const int dx[4] = {1,-1,0,0}, dy[4] = {0,0,-1,1};
#define int long long // fight me
int n; 
vector<int> xpos;
vector<int> ypos;

void dfs(int node, vector<bool>& visited, vector<vector<int>>& graph, int& counter){
	if(visited[node])return;
	visited[node] = true;
	counter++;
	for(int i: graph[node]){
		dfs(i,visited,graph,counter);
	}
	
}

bool check(int x){
	vector<vector<int>> graph(n);
	for(int i = 0; i < n-1; i++){
		for(int j = i+1; j < n; j++){
			if((xpos[i] - xpos[j]) * (xpos[i] - xpos[j]) + (ypos[i] - ypos[j]) * (ypos[i] - ypos[j]) <= x){
				graph[i].pb(j);
				graph[j].pb(i);
			}
		}
	}
	vector<bool> visited(n,false);
	int counter = 0;
	dfs(0,visited,graph,counter);
	return counter == n;
}

void doStuff(){
	ri(n);
	xpos.resize(n);
	ypos.resize(n);
	for(int i = 0; i < n; i++){
		ri(xpos[i],ypos[i]);
	}
	
	int start = 1, end = 1e9;
	while(start < end-1){
		int mid = start + (end-start)/2;
		if(check(mid)){
			end = mid;
		}
		else start = mid;
	}
	print(end);
}

signed main(){
	freopen("moocast.in","r",stdin);
	freopen("moocast.out","w",stdout);
	ios_base::sync_with_stdio(false);cin.tie(0);int t = 1;
	// ri(t);
	while(t--)doStuff();
    #ifdef LOCAL
    cerr << "Runtime: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	#endif
}