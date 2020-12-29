CREATE TABLE file_info(
    hash text primary key,
    record_time timestamptz,
    status integer,
    abs_path text
);
COMMENT ON COLUMN file_info.hash IS 'ifps hash';
COMMENT ON COLUMN file_info.record_time IS '记录生成时间';
COMMENT ON COLUMN file_info.status IS '状态';
COMMENT ON COLUMN file_info.abs_path IS '文件绝对路径';
