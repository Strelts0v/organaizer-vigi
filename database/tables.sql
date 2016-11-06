CREATE TABLE "business" (
	"id_business" INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE, 
	"head" VARCHAR(40),
	"deadline" DATE,
	"priority" INTEGER
);

CREATE TABLE "contacts" (
	"id_contact" INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE,
	"full_name" VARCHAR(50),
	"phone_numbers" VARCHAR(50),
	"email" VARCHAR(40)
);

CREATE TABLE "notes" (
	"id_note" INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE,
	"head" VARCHAR(50),
	"description" VARCHAR(300)
);