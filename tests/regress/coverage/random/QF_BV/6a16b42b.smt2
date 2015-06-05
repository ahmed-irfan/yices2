(set-info :source |fuzzsmt|)
(set-info :smt-lib-version 2.0)
(set-info :category "random")
(set-info :status unknown)
(set-logic QF_BV)
(declare-fun v0 () (_ BitVec 2))
(declare-fun v1 () (_ BitVec 112))
(assert (let ((e2(_ bv1120 11)))
(let ((e3(_ bv2 4)))
(let ((e4 ((_ rotate_left 70) v1)))
(let ((e5 (bvnot e2)))
(let ((e6 (ite (bvslt e2 ((_ zero_extend 9) v0)) (_ bv1 1) (_ bv0 1))))
(let ((e7 ((_ extract 1 0) v0)))
(let ((e8 (bvxnor v0 e7)))
(let ((e9 (bvnand e7 ((_ sign_extend 1) e6))))
(let ((e10 (ite (distinct ((_ sign_extend 110) e9) e4) (_ bv1 1) (_ bv0 1))))
(let ((e11 (bvnand e8 e9)))
(let ((e12 ((_ extract 0 0) e6)))
(let ((e13 (bvnand ((_ zero_extend 110) e8) e4)))
(let ((e14 (bvcomp v1 ((_ sign_extend 110) v0))))
(let ((e15 (bvcomp ((_ sign_extend 1) e12) e11)))
(let ((e16 ((_ zero_extend 104) e7)))
(let ((e17 (ite (distinct ((_ zero_extend 110) v0) v1) (_ bv1 1) (_ bv0 1))))
(let ((e18 (bvmul e5 ((_ sign_extend 10) e14))))
(let ((e19 (bvlshr e13 ((_ sign_extend 110) e8))))
(let ((e20 (ite (bvsgt e2 ((_ zero_extend 10) e17)) (_ bv1 1) (_ bv0 1))))
(let ((e21 (ite (distinct e8 ((_ sign_extend 1) e14)) (_ bv1 1) (_ bv0 1))))
(let ((e22 (bvnot e11)))
(let ((e23 ((_ repeat 63) e7)))
(let ((e24 (ite (= e13 e19) (_ bv1 1) (_ bv0 1))))
(let ((e25 (bvor e2 ((_ sign_extend 10) e15))))
(let ((e26 ((_ sign_extend 83) e25)))
(let ((e27 (bvsdiv ((_ sign_extend 1) e17) e7)))
(let ((e28 (bvand v1 ((_ sign_extend 111) e12))))
(let ((e29 (ite (distinct ((_ zero_extend 110) e7) e13) (_ bv1 1) (_ bv0 1))))
(let ((e30 (ite (distinct e25 ((_ sign_extend 9) v0)) (_ bv1 1) (_ bv0 1))))
(let ((e31 (ite (bvule e4 ((_ sign_extend 111) e21)) (_ bv1 1) (_ bv0 1))))
(let ((e32 (bvcomp ((_ zero_extend 111) e31) v1)))
(let ((e33 (ite (bvule e12 e12) (_ bv1 1) (_ bv0 1))))
(let ((e34 ((_ repeat 2) e5)))
(let ((e35 ((_ extract 0 0) e20)))
(let ((e36 (ite (= (_ bv1 1) ((_ extract 0 0) e8)) e25 ((_ sign_extend 9) e27))))
(let ((e37 ((_ sign_extend 66) e31)))
(let ((e38 (bvand e32 e29)))
(let ((e39 (bvxor e16 ((_ zero_extend 105) e21))))
(let ((e40 (bvmul ((_ sign_extend 45) e37) e28)))
(let ((e41 (bvneg e26)))
(let ((e42 (bvcomp ((_ sign_extend 111) e31) e19)))
(let ((e43 ((_ sign_extend 12) e11)))
(let ((e44 (ite (= (_ bv1 1) ((_ extract 0 0) e35)) e28 ((_ sign_extend 6) e16))))
(let ((e45 (bvxnor e2 e5)))
(let ((e46 (bvcomp e36 e5)))
(let ((e47 (ite (bvslt e4 ((_ sign_extend 110) e8)) (_ bv1 1) (_ bv0 1))))
(let ((e48 (bvashr ((_ sign_extend 10) e31) e45)))
(let ((e49 ((_ extract 0 0) e15)))
(let ((e50 (ite (bvsle ((_ zero_extend 110) e9) e13) (_ bv1 1) (_ bv0 1))))
(let ((e51 (ite (bvuge ((_ zero_extend 1) e6) v0) (_ bv1 1) (_ bv0 1))))
(let ((e52 ((_ extract 0 0) e29)))
(let ((e53 (bvsdiv ((_ zero_extend 111) e35) e44)))
(let ((e54 (bvlshr ((_ sign_extend 1) e20) e8)))
(let ((e55 ((_ rotate_right 0) e38)))
(let ((e56 (ite (bvsgt e3 ((_ sign_extend 3) e10)) (_ bv1 1) (_ bv0 1))))
(let ((e57 (bvsge ((_ zero_extend 18) e41) e19)))
(let ((e58 (distinct e6 e14)))
(let ((e59 (bvslt e30 e6)))
(let ((e60 (bvule ((_ sign_extend 1) e49) e7)))
(let ((e61 (distinct e28 ((_ sign_extend 111) e30))))
(let ((e62 (= e2 e5)))
(let ((e63 (bvuge e54 e9)))
(let ((e64 (= e23 ((_ zero_extend 124) e22))))
(let ((e65 (bvsle e28 ((_ zero_extend 110) e11))))
(let ((e66 (bvslt e51 e14)))
(let ((e67 (bvsle ((_ zero_extend 10) e47) e45)))
(let ((e68 (= ((_ sign_extend 110) e11) e13)))
(let ((e69 (bvsgt e16 ((_ zero_extend 105) e49))))
(let ((e70 (bvsle ((_ sign_extend 111) e29) e4)))
(let ((e71 (bvugt e14 e50)))
(let ((e72 (distinct v1 ((_ sign_extend 111) e49))))
(let ((e73 (distinct e48 ((_ zero_extend 10) e46))))
(let ((e74 (bvuge e28 ((_ sign_extend 111) e6))))
(let ((e75 (bvule v0 ((_ sign_extend 1) e52))))
(let ((e76 (bvule ((_ zero_extend 10) e52) e45)))
(let ((e77 (bvugt e52 e33)))
(let ((e78 (distinct e29 e49)))
(let ((e79 (bvsgt e33 e47)))
(let ((e80 (bvsge e28 ((_ zero_extend 111) e24))))
(let ((e81 (bvugt e51 e52)))
(let ((e82 (bvsle ((_ zero_extend 1) e35) e8)))
(let ((e83 (bvsgt e16 ((_ zero_extend 105) e33))))
(let ((e84 (bvsge e3 ((_ zero_extend 3) e14))))
(let ((e85 (= ((_ sign_extend 9) e7) e36)))
(let ((e86 (bvsge e3 ((_ sign_extend 3) e55))))
(let ((e87 (bvuge ((_ zero_extend 101) e5) e19)))
(let ((e88 (bvugt ((_ zero_extend 10) e56) e18)))
(let ((e89 (bvsle e45 ((_ sign_extend 9) e9))))
(let ((e90 (bvult ((_ zero_extend 93) e47) e41)))
(let ((e91 (distinct e22 ((_ sign_extend 1) e15))))
(let ((e92 (bvule e33 e31)))
(let ((e93 (bvugt ((_ sign_extend 21) e21) e34)))
(let ((e94 (bvule e5 e45)))
(let ((e95 (= e8 ((_ sign_extend 1) e52))))
(let ((e96 (bvult ((_ zero_extend 1) e46) e27)))
(let ((e97 (bvslt e38 e14)))
(let ((e98 (bvsgt e13 e44)))
(let ((e99 (bvsgt e44 ((_ sign_extend 111) e10))))
(let ((e100 (bvuge ((_ sign_extend 1) e46) e8)))
(let ((e101 (= e26 ((_ sign_extend 72) e34))))
(let ((e102 (bvsle e16 ((_ sign_extend 105) e55))))
(let ((e103 (bvsge ((_ zero_extend 111) e50) e4)))
(let ((e104 (bvslt e17 e24)))
(let ((e105 (distinct ((_ sign_extend 3) e15) e3)))
(let ((e106 (bvslt e20 e32)))
(let ((e107 (bvugt ((_ sign_extend 105) e12) e16)))
(let ((e108 (bvult e43 ((_ zero_extend 13) e15))))
(let ((e109 (bvugt e4 ((_ sign_extend 111) e38))))
(let ((e110 (bvslt e16 ((_ zero_extend 105) e47))))
(let ((e111 (bvsge e25 ((_ sign_extend 9) v0))))
(let ((e112 (bvuge e25 ((_ sign_extend 10) e42))))
(let ((e113 (bvsle ((_ zero_extend 9) e22) e2)))
(let ((e114 (bvsge ((_ zero_extend 110) v0) e53)))
(let ((e115 (bvugt ((_ sign_extend 101) e18) v1)))
(let ((e116 (bvsge ((_ zero_extend 83) e25) e41)))
(let ((e117 (bvult e36 ((_ zero_extend 7) e3))))
(let ((e118 (bvuge e14 e42)))
(let ((e119 (bvult e43 ((_ zero_extend 13) e29))))
(let ((e120 (bvult ((_ zero_extend 83) e48) e26)))
(let ((e121 (bvslt ((_ zero_extend 10) e50) e18)))
(let ((e122 (bvsle e19 ((_ zero_extend 18) e26))))
(let ((e123 (bvsge e41 ((_ sign_extend 27) e37))))
(let ((e124 (bvslt e16 e39)))
(let ((e125 (bvuge e2 e5)))
(let ((e126 (bvsge e28 ((_ sign_extend 90) e34))))
(let ((e127 (bvsle e23 ((_ sign_extend 125) e10))))
(let ((e128 (bvult e20 e35)))
(let ((e129 (bvuge e16 ((_ sign_extend 12) e41))))
(let ((e130 (bvule ((_ sign_extend 12) e11) e43)))
(let ((e131 (bvule e48 ((_ zero_extend 10) e30))))
(let ((e132 (bvugt e20 e52)))
(let ((e133 (bvugt ((_ sign_extend 105) e20) e39)))
(let ((e134 (= e5 ((_ zero_extend 10) e20))))
(let ((e135 (bvuge e36 ((_ sign_extend 10) e30))))
(let ((e136 (bvule ((_ sign_extend 1) e12) e7)))
(let ((e137 (bvult ((_ zero_extend 3) e38) e3)))
(let ((e138 (bvule e27 ((_ zero_extend 1) e14))))
(let ((e139 (bvslt e28 ((_ zero_extend 101) e18))))
(let ((e140 (bvsgt ((_ zero_extend 110) e7) v1)))
(let ((e141 (bvslt e28 ((_ sign_extend 111) e17))))
(let ((e142 (bvsgt e2 e45)))
(let ((e143 (bvuge e45 e45)))
(let ((e144 (bvsgt ((_ zero_extend 1) e21) v0)))
(let ((e145 (bvult e4 ((_ zero_extend 101) e5))))
(let ((e146 (bvslt ((_ zero_extend 111) e14) e44)))
(let ((e147 (bvslt e27 e9)))
(let ((e148 (bvult e16 ((_ sign_extend 105) e38))))
(let ((e149 (bvsge ((_ zero_extend 1) e56) e8)))
(let ((e150 (bvsle ((_ zero_extend 1) e29) e11)))
(let ((e151 (bvslt e55 e42)))
(let ((e152 (bvult e37 ((_ sign_extend 66) e32))))
(let ((e153 (bvult ((_ sign_extend 111) e51) e13)))
(let ((e154 (bvult ((_ sign_extend 93) e10) e41)))
(let ((e155 (bvult e27 e8)))
(let ((e156 (bvule ((_ sign_extend 111) e33) e28)))
(let ((e157 (bvule ((_ sign_extend 18) e41) e13)))
(let ((e158 (bvuge v1 ((_ sign_extend 111) e52))))
(let ((e159 (bvuge ((_ zero_extend 9) e11) e5)))
(let ((e160 (= e45 e48)))
(let ((e161 (bvsle e17 e29)))
(let ((e162 (bvugt e23 ((_ sign_extend 125) e33))))
(let ((e163 (bvsle v1 ((_ sign_extend 45) e37))))
(let ((e164 (= ((_ zero_extend 1) e17) e11)))
(let ((e165 (bvugt e15 e49)))
(let ((e166 (bvsge ((_ zero_extend 111) e49) e53)))
(let ((e167 (distinct ((_ zero_extend 10) e15) e48)))
(let ((e168 (bvule e35 e31)))
(let ((e169 (bvuge e6 e42)))
(let ((e170 (bvult e20 e6)))
(let ((e171 (bvult ((_ sign_extend 111) e24) v1)))
(let ((e172 (bvsgt ((_ zero_extend 10) e15) e25)))
(let ((e173 (distinct e34 ((_ zero_extend 21) e15))))
(let ((e174 (bvuge e16 ((_ sign_extend 105) e50))))
(let ((e175 (distinct e47 e47)))
(let ((e176 (bvugt e39 ((_ sign_extend 12) e41))))
(let ((e177 (bvslt e29 e21)))
(let ((e178 (= e38 e42)))
(let ((e179 (bvsle e36 ((_ sign_extend 10) e15))))
(let ((e180 (distinct ((_ sign_extend 39) e37) e16)))
(let ((e181 (= e16 ((_ zero_extend 105) e51))))
(let ((e182 (bvsgt e51 e14)))
(let ((e183 (= e18 ((_ sign_extend 9) e54))))
(let ((e184 (bvsge e20 e47)))
(let ((e185 (bvslt e35 e32)))
(let ((e186 (bvsgt e41 ((_ zero_extend 93) e29))))
(let ((e187 (bvugt e44 ((_ sign_extend 111) e30))))
(let ((e188 (bvsge e18 ((_ sign_extend 10) e52))))
(let ((e189 (bvsle v1 ((_ zero_extend 111) e21))))
(let ((e190 (bvugt e39 ((_ sign_extend 95) e48))))
(let ((e191 (= e48 ((_ sign_extend 9) e54))))
(let ((e192 (bvsge e12 e50)))
(let ((e193 (distinct e12 e21)))
(let ((e194 (bvslt ((_ zero_extend 1) e52) e11)))
(let ((e195 (bvsle ((_ zero_extend 10) e55) e36)))
(let ((e196 (distinct e39 ((_ sign_extend 104) e22))))
(let ((e197 (bvult e19 ((_ zero_extend 110) e9))))
(let ((e198 (bvsge e19 ((_ sign_extend 110) e7))))
(let ((e199 (bvslt ((_ zero_extend 101) e25) e44)))
(let ((e200 (bvsgt ((_ zero_extend 1) e10) e27)))
(let ((e201 (bvugt e9 ((_ zero_extend 1) e29))))
(let ((e202 (bvule ((_ zero_extend 105) e51) e39)))
(let ((e203 (bvsle e10 e46)))
(let ((e204 (distinct ((_ zero_extend 92) e27) e41)))
(let ((e205 (bvsge ((_ sign_extend 66) e10) e37)))
(let ((e206 (bvslt e39 ((_ zero_extend 105) e15))))
(let ((e207 (distinct e22 ((_ zero_extend 1) e17))))
(let ((e208 (distinct e14 e56)))
(let ((e209 (bvsgt ((_ sign_extend 27) e37) e41)))
(let ((e210 (bvuge ((_ sign_extend 125) e6) e23)))
(let ((e211 (distinct e3 ((_ zero_extend 3) e35))))
(let ((e212 (bvuge e12 e31)))
(let ((e213 (bvsge e30 e24)))
(let ((e214 (= ((_ sign_extend 111) e15) e53)))
(let ((e215 (distinct e27 ((_ sign_extend 1) e14))))
(let ((e216 (bvsgt e54 e8)))
(let ((e217 (bvule e39 ((_ zero_extend 105) e29))))
(let ((e218 (bvslt e13 ((_ zero_extend 111) e21))))
(let ((e219 (bvuge ((_ sign_extend 66) e33) e37)))
(let ((e220 (bvuge ((_ zero_extend 93) e15) e26)))
(let ((e221 (bvugt e56 e14)))
(let ((e222 (distinct ((_ sign_extend 1) e12) e54)))
(let ((e223 (bvsgt e20 e20)))
(let ((e224 (bvsge e49 e31)))
(let ((e225 (distinct ((_ sign_extend 111) e6) e13)))
(let ((e226 (bvslt e23 ((_ sign_extend 124) e54))))
(let ((e227 (= e13 e44)))
(let ((e228 (bvugt ((_ sign_extend 10) e29) e25)))
(let ((e229 (= e40 ((_ sign_extend 111) e6))))
(let ((e230 (or e74 e184)))
(let ((e231 (= e179 e177)))
(let ((e232 (= e155 e140)))
(let ((e233 (and e78 e163)))
(let ((e234 (xor e208 e69)))
(let ((e235 (or e117 e60)))
(let ((e236 (ite e90 e222 e209)))
(let ((e237 (ite e231 e95 e232)))
(let ((e238 (= e157 e147)))
(let ((e239 (not e65)))
(let ((e240 (ite e159 e202 e229)))
(let ((e241 (not e68)))
(let ((e242 (ite e105 e120 e86)))
(let ((e243 (= e185 e161)))
(let ((e244 (=> e81 e92)))
(let ((e245 (or e226 e189)))
(let ((e246 (xor e84 e72)))
(let ((e247 (xor e87 e180)))
(let ((e248 (xor e73 e137)))
(let ((e249 (xor e112 e156)))
(let ((e250 (not e196)))
(let ((e251 (ite e183 e91 e172)))
(let ((e252 (xor e144 e106)))
(let ((e253 (xor e64 e175)))
(let ((e254 (= e59 e168)))
(let ((e255 (= e164 e218)))
(let ((e256 (not e220)))
(let ((e257 (and e212 e152)))
(let ((e258 (or e110 e205)))
(let ((e259 (=> e235 e182)))
(let ((e260 (=> e57 e206)))
(let ((e261 (and e238 e256)))
(let ((e262 (or e251 e99)))
(let ((e263 (or e146 e121)))
(let ((e264 (xor e171 e80)))
(let ((e265 (= e167 e135)))
(let ((e266 (= e247 e83)))
(let ((e267 (ite e259 e248 e197)))
(let ((e268 (xor e143 e214)))
(let ((e269 (ite e138 e71 e199)))
(let ((e270 (not e162)))
(let ((e271 (or e241 e269)))
(let ((e272 (and e176 e249)))
(let ((e273 (xor e89 e89)))
(let ((e274 (xor e170 e257)))
(let ((e275 (=> e70 e126)))
(let ((e276 (= e239 e160)))
(let ((e277 (not e187)))
(let ((e278 (= e109 e211)))
(let ((e279 (not e107)))
(let ((e280 (not e224)))
(let ((e281 (=> e217 e133)))
(let ((e282 (= e278 e264)))
(let ((e283 (=> e150 e142)))
(let ((e284 (not e98)))
(let ((e285 (and e260 e266)))
(let ((e286 (xor e103 e145)))
(let ((e287 (xor e115 e250)))
(let ((e288 (or e271 e125)))
(let ((e289 (and e58 e219)))
(let ((e290 (=> e108 e213)))
(let ((e291 (or e268 e85)))
(let ((e292 (xor e166 e124)))
(let ((e293 (= e132 e123)))
(let ((e294 (=> e275 e67)))
(let ((e295 (= e245 e101)))
(let ((e296 (=> e223 e181)))
(let ((e297 (and e289 e148)))
(let ((e298 (ite e255 e188 e201)))
(let ((e299 (and e230 e97)))
(let ((e300 (ite e154 e233 e296)))
(let ((e301 (or e207 e63)))
(let ((e302 (= e141 e88)))
(let ((e303 (and e158 e100)))
(let ((e304 (or e62 e265)))
(let ((e305 (and e261 e227)))
(let ((e306 (ite e234 e270 e273)))
(let ((e307 (= e102 e252)))
(let ((e308 (or e203 e104)))
(let ((e309 (xor e134 e305)))
(let ((e310 (=> e307 e93)))
(let ((e311 (ite e301 e274 e253)))
(let ((e312 (and e194 e122)))
(let ((e313 (=> e258 e280)))
(let ((e314 (and e313 e151)))
(let ((e315 (ite e96 e293 e128)))
(let ((e316 (or e228 e215)))
(let ((e317 (and e192 e306)))
(let ((e318 (or e287 e174)))
(let ((e319 (= e295 e243)))
(let ((e320 (xor e294 e61)))
(let ((e321 (xor e240 e116)))
(let ((e322 (or e210 e131)))
(let ((e323 (and e149 e153)))
(let ((e324 (xor e279 e178)))
(let ((e325 (or e254 e320)))
(let ((e326 (xor e113 e312)))
(let ((e327 (xor e300 e263)))
(let ((e328 (=> e204 e299)))
(let ((e329 (= e82 e118)))
(let ((e330 (not e286)))
(let ((e331 (xor e302 e195)))
(let ((e332 (ite e193 e330 e328)))
(let ((e333 (or e326 e324)))
(let ((e334 (not e200)))
(let ((e335 (xor e139 e332)))
(let ((e336 (= e66 e321)))
(let ((e337 (ite e165 e284 e292)))
(let ((e338 (not e298)))
(let ((e339 (= e315 e169)))
(let ((e340 (not e338)))
(let ((e341 (= e304 e317)))
(let ((e342 (= e267 e130)))
(let ((e343 (ite e75 e327 e331)))
(let ((e344 (=> e244 e191)))
(let ((e345 (or e341 e282)))
(let ((e346 (=> e329 e119)))
(let ((e347 (xor e311 e281)))
(let ((e348 (or e246 e136)))
(let ((e349 (not e173)))
(let ((e350 (not e319)))
(let ((e351 (xor e221 e288)))
(let ((e352 (=> e303 e308)))
(let ((e353 (not e297)))
(let ((e354 (not e325)))
(let ((e355 (not e339)))
(let ((e356 (ite e79 e314 e349)))
(let ((e357 (not e216)))
(let ((e358 (ite e242 e335 e310)))
(let ((e359 (not e346)))
(let ((e360 (or e347 e356)))
(let ((e361 (=> e127 e352)))
(let ((e362 (=> e353 e322)))
(let ((e363 (and e351 e359)))
(let ((e364 (ite e334 e186 e285)))
(let ((e365 (=> e236 e362)))
(let ((e366 (xor e262 e358)))
(let ((e367 (ite e363 e283 e364)))
(let ((e368 (ite e111 e348 e94)))
(let ((e369 (or e76 e333)))
(let ((e370 (=> e290 e369)))
(let ((e371 (and e342 e367)))
(let ((e372 (= e343 e337)))
(let ((e373 (=> e366 e316)))
(let ((e374 (or e336 e372)))
(let ((e375 (not e198)))
(let ((e376 (and e345 e373)))
(let ((e377 (or e225 e376)))
(let ((e378 (xor e357 e276)))
(let ((e379 (and e350 e77)))
(let ((e380 (ite e323 e360 e190)))
(let ((e381 (=> e344 e129)))
(let ((e382 (=> e114 e277)))
(let ((e383 (xor e340 e237)))
(let ((e384 (not e378)))
(let ((e385 (not e309)))
(let ((e386 (=> e365 e383)))
(let ((e387 (or e355 e374)))
(let ((e388 (or e379 e368)))
(let ((e389 (=> e380 e386)))
(let ((e390 (or e291 e384)))
(let ((e391 (xor e390 e354)))
(let ((e392 (xor e389 e377)))
(let ((e393 (xor e387 e381)))
(let ((e394 (= e385 e361)))
(let ((e395 (=> e370 e318)))
(let ((e396 (or e394 e394)))
(let ((e397 (= e388 e393)))
(let ((e398 (=> e371 e396)))
(let ((e399 (and e391 e272)))
(let ((e400 (= e399 e395)))
(let ((e401 (not e400)))
(let ((e402 (not e397)))
(let ((e403 (ite e382 e402 e375)))
(let ((e404 (= e398 e398)))
(let ((e405 (=> e392 e392)))
(let ((e406 (not e405)))
(let ((e407 (not e403)))
(let ((e408 (xor e407 e401)))
(let ((e409 (= e406 e406)))
(let ((e410 (= e409 e409)))
(let ((e411 (and e404 e404)))
(let ((e412 (not e408)))
(let ((e413 (ite e411 e412 e410)))
(let ((e414 (and e413 (not (= e7 (_ bv0 2))))))
(let ((e415 (and e414 (not (= e7 (bvnot (_ bv0 2)))))))
(let ((e416 (and e415 (not (= e44 (_ bv0 112))))))
(let ((e417 (and e416 (not (= e44 (bvnot (_ bv0 112)))))))
e417
)))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))

(check-sat)