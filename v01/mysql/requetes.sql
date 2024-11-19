-- ==============================================
-- _users
-- ==============================================

create table _users (
    _id int not null auto_increment primary key,
    _username varchar(50) not null,
    _password varchar(50) not null
);

select * from _users;

-- ==============================================
