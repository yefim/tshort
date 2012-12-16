CREATE TABLE shorturl (
  id INTEGER PRIMARY KEY,
  keyword VARCHAR(20) NOT NULL UNIQUE,
  url VARCHAR(200) NOT NULL,
  hits INTEGER,
  created_at TIMESTAMP,
  updated_at TIMESTAMP,
  lock_revision INTEGER
);
