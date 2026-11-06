# Rulebook Game Selection

最终版：**10 款，6 款 Weight<2、4 款 2≤Weight<3**。保留蓝色表头、交替行底色及可点击的 BGG / 原始规则 PDF 链接。候选发现由 Python 执行；规则完整性审核是有来源证据的人工/LLM 辅助判断，二者分开保存。

## Selection algorithm

Protocol v2 was frozen before inspecting the newly generated candidate order. Python reads all **27,780 records** in the independent [BGG-derived Kaggle dataset, version 4](https://www.kaggle.com/datasets/jvanelteren/boardgamegeek-reviews/versions/4), released **1 February 2025**. These are historical values, not live BGG readings. The earlier LLM-proposed list is not an input.

1. Keep base games with `1 <= averageweight < 3`, `usersrated >= 1000`, and `numweights >= 30`; do not impute missing data.
2. Create Weight<2 and 2≤Weight<3 strata. Sort each by **rating count descending, numeric BGG ID ascending**. The full queues contain **1,428 / 1,467** games.
3. Inspect current official English base rules in that order. Require **1–9 total physical PDF pages**, including mandatory supplements, and explicit evidence for setup, actions, termination, scoring, special rules and all necessary component data. Link required HTML FAQs separately. Record every rejection. Missing/pending reviews block progression.
4. Retain the first **6 / 4 explicit passes**, then display by raw Weight ascending, BGG ID ascending. The result required **243 ordered decisions**. Mechanism descriptions do not affect selection.

The script bundles the entire six-column data projection and all audit records. A downloaded PDF requires a recorded SHA-256; browser-only evidence must be labelled. The program validates annotations, not their semantic truth. Changed evidence requires re-review. Popularity thresholds and the historical dataset define a sampling frame, not a representative sample of every BGG game. Identical frozen data and audits reproduce identical results; a new data snapshot or revised audit may change them.

## Run

Python **3.9+**, standard library only; tested with this Mac's Python 3.9.6. Open `game_selection_report.html` directly in a browser.

```sh
# Generate the report offline from the bundled frozen inputs.
python3 select_games.py

# Rebuild both complete candidate queues without reading audit annotations.
python3 select_games.py --discover-only --out-dir discovery

# Export readable CSV, audit JSON, protocol and provenance.
python3 select_games.py --out-dir result --export-inputs inputs

# Independently download the pinned original CSV and verify its normalization.
python3 select_games.py --download-source --out-dir source_check

# Inspect a record, or rerun against independently revised audit annotations.
python3 select_games.py --explain 215 --out-dir explanation
python3 select_games.py --reviews inputs/audit_records.json --out-dir revised_result
```

Network access is needed only for `--download-source`. This command was actually executed on **4 November 2026**: the fresh 110,063,542-byte original matched both the pinned raw hash and the bundled projection. The lookup procedure and version policy are exported in `protocol_frozen.md`. The default exit code is 0 for a complete selection; 2 signals an incomplete audit prefix; 1 signals invalid input or a retrieval error.

## Two actual final executions — 4 November 2026

The final script was executed in **two separate Python 3.9.6 processes**, with separate output directories and identical bundled inputs. Both exited **0**. Candidate queues, selected order, selection JSON and HTML were **byte-for-byte identical**. Every selected original PDF was also rechecked locally for physical pages and SHA-256.

| Output | Matching SHA-256 |
|---|---|
| Candidate queues | `9214a4be1fec7d4a920c609e20b585e7c35d501db7e6318d5d255d7f9ede3090` |
| Selection JSON | `77d270f46bb8a057cb119e3c520ed67eedf46872235e5aa476ae178e10ceedf6` |
| HTML report | `464e3105d5ce04036450242f01d299286ad686cc3c707bd1d0cd618497eb7db9` |

Raw CSV SHA-256: `d45af2eb43e6f595cd9d41c639882d71b2e57b6143b7409ada02cac5d2d4c91f`.

Projection SHA-256: `790a521e28914b6bbc442578bb91e416645d234cb809dcce871e101fe335fe63`.

Final BGG IDs in display order: `133473, 39856, 50, 98778, 65244, 230802, 394, 2389, 269210, 215`.

To repeat the comparison, run the script with `--out-dir run_1` and `--out-dir run_2` and compare `candidate_queues.json`, `selection_result.json`, and `game_selection_report.html` in both directories.

导师审核建议：Dixit 的图片与开放式线索、Tichu 的抢断优先级，以及 Hanabi 原规则中的计分文字笔误，值得 Massimo 重点确认；具体证据在 HTML 可展开审核栏中。它们的入选不代表已证明适合自动生成 `.rl`。现有 Kuhn Poker、CMake 及其他 Rulebook 项目代码未修改。
