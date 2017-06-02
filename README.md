[![Build Status](https://travis-ci.org/RedisLabsModules/RediSearch.svg?branch=master)](https://travis-ci.org/RedisLabsModules/RediSearch)

# RediSearch 

### Full-Text search over redis by RedisLabs

### See Full Documentation at [http://redisearch.io](http://redisearch.io)

### Latest Release: [0.16 (Preview)](https://github.com/RedisLabsModules/RediSearch/releases/tag/v0.16)

# Client Libraries

* **Python**: [https://github.com/RedisLabs/redisearch-py](https://github.com/RedisLabs/redisearch-py)

* **Java**: [https://github.com/RedisLabs/JRediSearch](https://github.com/RedisLabs/JRediSearch)

## Community Libraries:

* **PHP**: [https://github.com/ethanhann/redisearch-php](https://github.com/ethanhann/redisearch-php) (By Ethan Hann)

* **Ruby on Rails**: [https://github.com/dmitrypol/redi_search_rails](https://github.com/dmitrypol/redi_search_rails) (By Dmitry Polyakovsky)

* **.Net**: [https://libraries.io/nuget/NRediSearch](https://libraries.io/nuget/NRediSearch) (By Marc Gravell)

# Overview

Redisearch implements a search engine on top of redis, but unlike other redis 
search libraries, it does not use internal data structures like sorted sets.

Inverted indexes are stored as a special compressed data type that allows for fast
indexing and search speed, and low memory footprint. 

This also enables more advanced features, like exact phrase matching and numeric filtering for text queries, 
that are not possible or efficient with traditional redis search approaches. 

## Primary Features:

* Full-Text indexing of multiple fields in documents.
* Incremental indexing without performance loss.
* Document ranking (provided manually by the user at index time).
* Field weights.
* Complex boolean queries with AND, OR, NOT operators between sub-queries.
* Prefix matching in full-text queries.
* Auto-complete suggestions (with fuzzy prefix suggestions)
* Exact Phrase Search.
* Stemming based query expansion in [many languages](http://redisearch.io/Stemming/) (using [Snowball](http://snowballstem.org/)).
* Limiting searches to specific document fields (up to 32 fields supported).
* Numeric filters and ranges.
* Geographical search utlizing redis' own GEO commands.
* Supports any utf-8 encoded text.
* Retrieve full document content or just ids.
* Automatically index existing HASH keys as documents.
* Document Deletion (Update can be done by deletion and then re-insertion).
* Sortable properties (i.e. sorting users by age or name).

### Not *yet* supported:

* Spelling correction
* Aggregations

### License: AGPL

Which basically means you can freely use this for your own projects without "virality" to your code,
as long as you're not modifying the module itself. See [This Blog Post](https://redislabs.com/blog/why-redis-labs-modules-are-agpl/) for more details.

### Note About Stability

RediSearch is still under development and can be considered Alpha. While we've tested it extensively with big data-sets and very high workloads, and it is very stable - the API itself may change. You are welcome to use it, but keep in mind future versions might change things.
 
